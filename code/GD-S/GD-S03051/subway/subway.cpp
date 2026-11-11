#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,p,x,y,s,t,e,mi=1e18,b[210][N];
struct An{
	long long i,g;
};
struct No{
	long long w,s;
	An a[25];
}a[510];
bool vi[510],vii[N];
void dfs(long long x,long long y,long long s){
	long long c=0;
	if(x==t){
		for(int i=1;i<=a[x].s;i++){
			if(a[x].a[i].i==y){
				c=a[x].a[i].g;
				break;
			}
		}
		s+=c;		
		if(s<mi)mi=s;
		return;
	}
	vi[x]=1;
	for(int i=1;i<=a[x].s;i++){
		if(a[x].a[i].i==y){
			c=a[x].a[i].g;
			break;
		}
	}
	for(int i=1;i<=a[x].s;i++){
		if(a[x].a[i].i==y||vii[a[x].a[i].i])continue;
		for(int j=1;j<=n;j++){
			if(b[a[x].a[i].i][j]==x||vi[b[a[x].a[i].i][j]]||(a[b[a[x].a[i].i][j]].s==1&&b[a[x].a[i].i][j]!=t))continue;
			vii[a[x].a[i].i]=1;
			dfs(b[a[x].a[i].i][j],a[x].a[i].i,s+a[x].a[i].g+c);
			vii[a[x].a[i].i]=0;
		}
	}
	vi[x]=0;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>a[i].w;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>e;
			a[y].a[++a[y].s].g=e;
			a[y].a[a[y].s].i=i;
			b[i][j]=y;
		}	
	}
	for(int i=1;i<=p;i++){
		cin>>s>>t;
		mi=1e18;
		dfs(s,0,a[s].w+a[t].w);
		cout<<mi<<endl;
	}
	return 0;
} 
