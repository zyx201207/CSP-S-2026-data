#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],k[205],a[205][N],t[205][N];
bool vis[205][N],flag;
int DFS(int l,int r,int last){
	if(l>=r) return 0;
	for(int i=1;i<=n;i++)
		vis[i][l]=true;
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=0,p=0;
		flag=false;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==l){
				flag=true;
				p=j;
				break;
			}
		}
		if(flag==true){
			for(int j=p;j<=k[i];j++){
				if(vis[i][j]==false){
					vis[i][j]=true;
					sum=DFS(j,r,i)+t[i][j];
					if(last!=i) sum+=t[last][j];
					vis[i][j]=false;
				}
			}
			ans+=sum;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		cout<<DFS(l,r,0)+w[l]+w[r]<<'\n';
	}
	return 0;
}
