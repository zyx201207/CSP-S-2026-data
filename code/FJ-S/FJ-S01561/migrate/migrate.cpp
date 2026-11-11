#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int> ;
int C,T,a[2000100],d[5010],ds[5010];
int s[5010];
vector<int>v[2000100];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		int n,d1;
		cin>>n>>d1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int t=1;t<=n;t++){
			for(int i=1;i<=n;i++)d[i]=INF,s[i]=0;
			d[t]=0;
			for(int i=t;i<=n;i++){
				int j=i+1;
				while(j<=n&&abs(a[i]-a[j])<=d1){
					d[j]=min(d[j],d[i]+1);
					j++;
				}
			}
			for(int i=t;i>=1;i--){
				int j=i-1;
				while(j>=1&&abs(a[i]-a[j])<=d1){
					d[j]=min(d[j],d[i]+1);
					j--;
				}
			}
			for(int i=1;i<=n;i++){
				ds[i]=INF;
			}
			ds[t]=0;
			for(int i=t;i<=n;i++){
				int j=i+1;
				while(j<=n&&abs(a[i]-a[j])<=d1){
					if(d[j]==ds[i]+1)s[j]++;
					ds[j]=min(ds[j],ds[i]+1);
					j++;
				}
			}
			for(int i=t;i>=1;i--){
				int j=i-1;
				while(j>=1&&abs(a[i]-a[j])<=d1){
					if(d[j]==ds[i]+1)s[j]++;
					ds[j]=min(ds[j],ds[i]+1);
					j--;
				}
			}
			for(int i=1;i<=n;i++){
				if(s[i]==2)ans++;
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

