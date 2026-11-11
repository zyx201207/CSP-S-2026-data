#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
const int M=2e6+9;
int n[N],d[N];
int sum,ans;

int sea[10000][10000];
bool vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>sea[i][j];
			vis[sea[i][j]]=1;
		}
	}
	for(int i=1;i<=t;i++){
		sum=0;
		for(int j=1;j<=n[i];j++){
			sum=sea[i][j]+d[i];	
			if(vis[sum]==1)ans++;
		}
	}
	cout<<ans;
	return 0;	
}
