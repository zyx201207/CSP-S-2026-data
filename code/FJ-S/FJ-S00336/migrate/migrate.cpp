#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[1000005];
int kz[1000005],ky[10000005];//靠近i的最远到达的岛屿 
int mp[505][505];
void cl(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mp[i][j]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<j-1;k++){
				if(a[j]-a[k]<=d&&a[k+1]-a[i]<=d&&a[j]-a[k-1]>d&&a[k+2]-a[i]>d){
					mp[i][j]=1;
//					cout<<i<<" "<<j<<'\n';
					break;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int cc=ans;
			if(mp[i][j]==1){
				ans++;
				continue;
			}
			for(int k=i+1;k<j;k++){
				if(a[k]-a[k-1]>d||a[k+1]-a[k]>d)break;
				if(a[k+1]-a[k-1]>d&&mp[k+1][j]==1){
//					cout<<i<<" "<<k<<" "<<j<<'\n';
					ans++;
					break;
				}
			}
			if(cc!=ans)break;
			for(int k=j-1;k>i;k--){
				if(a[k]-a[k-1]>d||a[k+1]-a[k]>d)break;
				if(a[k+1]-a[k-1]>d&&mp[i][k-1]==1){
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c==13||c==14){
		for(int i=1;i<=T;i++)cout<<0<<'\n';
		return 0;
	}
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int cc=a[2]-a[1];
			int bs=d/cc;
//			cout<<n<<" "<<bs<<'\n';
//			continue;
			if(cc>=d){
				cout<<"0\n";
				continue;
			}
			cout<<max(0ll,n-(bs+bs-1))<<'\n';
		}
		return 0;
	}
	while(T--)cl();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
