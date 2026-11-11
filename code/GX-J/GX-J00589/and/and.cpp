#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans;
int vis[N],a[N];
vector<int>g[35];
void solve(int x,int id){
	for(int i=1;x!=0;i++){
		if(x%2==1)g[i].push_back(id);
		x=x/2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	int cnt=30;
	while(1){
		for(int i=1;i<=n;i++){
			if(vis[i]==1)solve(a[i],i);
			vis[i]=0;
		}
		int f=0,sum=(1<<30)-1;
		for(int i=cnt;i>=1;i--){
			if((int)g[i].size()>=m){
				f=1;
				for(int j=0;j<(int)g[i].size();j++){
					vis[g[i][j]]=1;
					sum=sum&a[g[i][j]];
				}
				cnt=i-1;
				break;
			}
		}
		if(f==0)break;
		ans=sum;
		for(int i=1;i<=30;i++){
			g[i].clear();
		}
	}
	cout<<ans;
	return 0;
}
