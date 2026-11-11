#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2*1e6+5;
int c,t;
unsigned int n,d;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				int cnt=0;
				//cout<<"newone"<<endl;
				//if(abs(a[i]-a[j])<=d){cnt++;cout<<i<<" "<<j<<" abs(a[i]-a[j])<=d "<<cnt<<endl;}
				for(int k=i+1;k<j;k++){
					if(abs(a[i]-a[k])<=d&&abs(a[j]-a[k])<=d){
						cnt++;
						//cout<<k<<" "<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<abs(a[i]-a[k])<<" "<<abs(a[j]-a[k])<<" "<<cnt<<endl;
					}
					if(cnt>2)break;
					//cout<<"test"<<endl;
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
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


0 1
5 3
-2 -1 0 1 2
*/

