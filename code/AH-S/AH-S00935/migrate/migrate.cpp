#include <bits/stdc++.h>
using namespace std;
long long a[2000005],b[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n;
			long long m,t=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			t=a[2]-a[1];
			if(t>=m){
				cout<<0<<endl;
				continue;
			}
			m/=t;
			if(n-2*m+1>0) cout<<n-2*m+1;
			else cout<<0;
			cout<<endl;
		}
		return 0;
	}
	while(t--){
		long long n,m;
		char f=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=1&&i!=1){
				f=1;
			}
			b[i]=0;
		}
		if(!f){
			if(n-2*m+1>0) cout<<n-2*m+1;
			else cout<<0;
			cout<<endl;
			continue;
		}
		int j=2,ans=0;
		for(int i=1;i<=n;i++){
			for(;j<=n;j++){
				if(a[i]+m<a[j]){
					break;
				}
			}
			j--;
			int k=j+1;
			for(;k<=n;k++){
				if(a[j]+m<a[k]){
					break;
				}
			}
			if(k==n+1){
				continue;
			}
			k--;
			if(a[j-1]+m>=a[k]){
				if(a[j-2]+m<a[k]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
