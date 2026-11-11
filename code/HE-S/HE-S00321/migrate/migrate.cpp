#include<bits\stdc++.h>
using namespace std;
#define ll long long

int arr[2000001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		sort(arr+1,arr+1+n);
		map<int,int> mp;
		for(int i=1;i<=n;i++) cin>>arr[i];
		int d1=abs(arr[2]-arr[1]);
		for(int i=1;i<=arr[n]+d+d1;i++){
			mp[i]=0; 
		}
		for(int i=1;i<=n;i++){
			mp[arr[i]]=1; 
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=(mp[arr[i]+d+d1]!=0?1:0);

		}
		cout<<ans<<endl;
	}


	return 0;
} 

