#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=N*N;
int c,n,m,d,q;
int w[N];
int a[N][N];
int t[N][N];

bool vis[N];
int st[N];


int idx;
int e[M],ne[M],h[M];
int vv[M];
void add(int u,int v,int cc){
	e[idx]=v;
	vv[idx]=cc;
	ne[idx]=h[u];
	h[u]=idx++;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				add(a[i][j],a[i][l],t[i][j]+t[i][l]);
				add(a[i][l],a[i][j],t[i][j]+t[i][l]);
			}
		}
	}
	for(int o=1;o<=q;o++){
		int l,r;
		cin>>l>>r;
		long long ans=w[l]+w[r];
		memset(st,0x3f,sizeof st);
		memset(vis,false,sizeof vis);
		st[l]=0;
		
		for(int i=1;i<=m;i++){
			int idd=0,minn=0x3f3f3f3f;
			for(int i=1;i<=m;i++){
				
				if(vis[i]) continue;
				//cout<<i<<' '<<vis[i]<<endl;
				if(st[i]<minn){
					minn=st[i];
					idd=i;
				}
			}
			
			//cout<<idd<<':';
			
			for(int i=h[idd];i!=-1;i=ne[i]){
				int j=e[i];
				int cc=vv[i];
				//cout<<cc;
				st[j]=min(st[j],minn+cc);
				//cout<<j<<','<<st[j]<<' ';
			}vis[idd]=true;
			//cout<<endl;
			
		}
		
		cout<<ans+st[r]<<endl;
	}
	
	
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
