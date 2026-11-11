#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],cnt;
int vis[N],tim[N];
void solve(int l,int r){
	for(int i=l;i<=r;i++) vis[i]=tim[i]=0;
	vis[l]=1,tim[l]=1;
	for(int i=l;i<=r;i++){
		for(int j=i+1;j<=r;j++){
			if(x[j]-x[i]<=d){
				if(!vis[j]){
					vis[j]=vis[i]+1;
					tim[j]=tim[i];
				}
				else if(vis[j]==vis[i]+1){
					tim[j]+=tim[i];
				}
			}
			else break;
		}
	}
	if(tim[r]==2) cnt++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				solve(i,j);
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}/*

0 1
5 2
1 2 3 4 5

0 1
6 2
-4 -3 -2 -1 3 6


*/
