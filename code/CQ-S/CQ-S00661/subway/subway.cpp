#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int c,n,m,d,q;
struct Edge{
	int num;
	int a,t;
}fa[50005];
bool cmp(Edge ww,Edge ss){
	return ww.a<ss.a; 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	int w[n+1],sum=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,d;i<=n;i++){
		cin>>d;
		for(int j=1,b,c;j<=d;j++){
			cin>>b>>c;
			sum+=1;
			fa[sum].num=i;
			fa[sum].a=b;
			fa[sum].t=c;
		}
	}
	sort(fa+1,fa+sum+1,cmp);
//	for(int i=1;i<=sum;i++){
//		cout<<fa[i].num<<" "<<fa[i].a<<" "<<fa[i].t<<endl;
//	}
	int g[m+1][m+1];
	memset(g,0x3f,sizeof(g)); 
	for(int i=2;i<=sum;i++){
		if(fa[i].a==fa[i-1].a&&fa[i].num!=fa[i-1].num){
			int x=(int)fa[i].num,y=(int)fa[i-1].num;
//			cout<<x<<" "<<fa[i].a<<" "<<fa[i].t<<endl;
//			cout<<y<<" "<<fa[i-1].a<<" "<<fa[i-1].t<<endl;
			int qq=(int)fa[i].t+fa[i-1].t;
//			cout<<qq<<endl;
			g[x][y]=qq,g[y][x]=qq;	
			continue;		
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<g[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		int ii=0,jj=0,sum1=0,sum2=0;
		bool flag=false;
		for(int i=1;i<=sum;i++){
			if(fa[i].a==x){
				flag=true;
				if(ii==0) ii=i;
				sum1+=1;
			}else if(flag&&fa[i].a!=x){
				break;
			}
		}
		flag=false;
		for(int j=1;j<=sum;j++){
			if(fa[j].a==y){
				flag=true;
				if(jj==0) jj=j;
				sum2+=1;
			}else if(flag&&fa[j].a!=y){
				break;
			}
		}
//		cout<<ii<<" "<<sum1<<" "<<jj<<" "<<sum2<<endl;
		int num2=1e6;
		for(int i=ii;i<=ii+sum1-1;i++){
			for(int j=jj;j<=jj+sum2-1;j++){
				num2=min(num2,fa[i].t+fa[j].t+g[fa[i].num][fa[j].num]);
			}
		}
		cout<<ans+num2<<endl;
	}
	return 0;
}
//Trick||Treat!
//0 2 5 20 2  4 1 9 2 5  3 1 5 2 7 4 6  3 2 3 3 4 5 7  1 3  1 2       32 17
//0 3 7 20 2  8 3 6 1 7 2 9  3 1 4 2 5 5 100  3 2 6 3 1 7 2  4 3 2 5 100 4 6 6 7  1 6 2 3        35   16
//屎山代码ing 死人微活 
