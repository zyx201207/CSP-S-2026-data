// GZ-S00399 µËÍûÔÆ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000005];
ll c[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int p,T,n,d;
	cin>>p>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
			if(n<4){
			cout<<0;
			continue;
		}
		for(int i=2;i<=n;i++){
			c[i]=a[i]-a[i-1];
		}
		int cnt=0;
		for(int i=2;i<=n-2;i++){
			if(c[i+1]+c[i+2]<=d&&c[i]+c[i+1]<=d){
			cnt++;	
			}
		}
		cout<<cnt<<endl;
	}
}
