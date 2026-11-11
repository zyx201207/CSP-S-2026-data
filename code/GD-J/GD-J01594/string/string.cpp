#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+5;
ll a[N];
char c[N];
ll n;
ll ans = 0;
int main(){
	freopen("string2.in","r",stdin);
	freopen("string2.out","w",stdout);
	scanf("%lld",&n);
	for(ll i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		scanf("%lld%lld",&a[i],&c[i]);
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		if(c[2]==c[2]){
			cout<<0<<endl;
		}
		return 0;
	}
	if(n%2==0 or n%2==1){
		for(ll i = 1,j = n;i<=n/2,j>n/2;i++,j--){
			if(a[i]==a[j] and c[i]==c[j]){
				//cout<<"1"<<endl;
				continue; 
			}
			if(a[i]!=a[j] and c[i]!=c[j]){
				//cout<<2<<" ";
				if(a[j]>a[i]){
					ans+=a[i];
					//cout<<"ans+"<<a[i]<<endl; 
					ans+=a[j]-a[i];
					//cout<<"ans+"<<a[j]-a[i]<<endl; 
					a[j-1]+=a[j]-a[i];
					//cout<<ans<<endl;
					continue;
				}else{
					ans+=a[j];
					//cout<<"ans+"<<a[j]<<endl;
					ans+=a[i]-a[j];
					a[i+1] += a[i]-a[j];
					//cout<<"ans+"<<a[i]-a[j]<<endl;
					//cout<<ans<<endl;
					continue;
				}
			}if(a[i]!=a[j] and c[i]==c[j]){
				//cout<<3<<" ";
				if(a[i]>a[j]){
					ans+=a[i]-a[j];
					//cout<<"ans+"<<a[i]-a[j]<<endl;
					a[i+1]+=a[i]-a[j];
					//cout<<ans<<endl;
					continue;
				}else{
					ans+=a[j]-a[i];
					//cout<<"ans+"<<a[j]-a[i]<<endl;
					a[j-1]+=a[j]-a[i];
					//cout<<ans<<endl;
					continue;
				}
			}
			if(a[i]==a[j] and c[i]!=c[j]){
				//cout<<4<<" ";
				ans+=a[i];
				//cout<<"ans+="<<a[i]<<endl;
				//cout<<ans<<endl;
				continue; 
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
