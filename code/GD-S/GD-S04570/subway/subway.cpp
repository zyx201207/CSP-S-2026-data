#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int a[N][N],t[N][N];
int w[N],k[N];
int c,n,m,d,q;
int xx,yy,ex,ey;
int sum=0;
int st,ed;
struct samee{
	int x1,x2;
	int val;
}flag[N];
int ti;
void find(int x,int y){
	ti+=w[y];
	int xx=0,yy=0;
	int ex=0,ey=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==y)
				ex=i,ey=j;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==x&&!xx&&!yy){
				xx=i,yy=j;
			}else if(a[i][j]==x&&xx||yy){
				if(xx==ex) xx=ex,yy=ey;
				else xx=i,yy=ey;
			}
}

void work(int cur){
	ti+=w[cur];
	ti+=t[ey][ex];
	if(xx=ex) return;
	else{
		int cnt=INT_MAX;
		if(xx=1){
			for(int i=1;i<=sum;i++){
				int nw=t[2][flag[i].x2]+w[flag[i].val]; 
				cnt=min(cnt,nw);
			}
		}else{
			for(int i=1;i<=sum;i++){
				int nw=t[1][flag[i].x1]+w[flag[i].val];
				cnt=min(cnt,nw);
			}
		}
		ti+=cnt;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int aa;cin>>aa;k[i]=aa;
		for(int j=1;j<=aa;j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++){
			if(a[1][i]==a[2][j]&&a[1][i]!=0&&a[2][j]!=0){
				flag[++sum].val=a[1][i];
				flag[sum].x1=i,flag[sum].x2=j;
			}
		}
	cout<<endl;
	for(int i=1;i<=sum;i++)cout<<flag[i].val<<endl;
	
	
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		xx=yy=ex=ey=ti=st=ed=0;		
		find(st,ed); 
		work(st);
		cout<<ti<<endl;
	}

	return 0;
}

/*0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 

*/


