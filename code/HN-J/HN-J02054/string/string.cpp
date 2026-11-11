#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,s=0,ans=0;
	ll sum=0;
	cin>>n;
	ll k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum=sum>>1;
	for(int i=1;i<=n;i++){
		ll t=0;
		if(a[i]>sum){
			t=sum;
			sum=0;
		}
		else{
			t=a[i];
			sum-=t;
		}
//		cout<<t<<"\n";
//		for(int j=1;j<=t;j++){
//			cout<<c[i];
//		}cout<<"\n";
		while(t>0){
			if(s>0){
				if(s>t){
					s-=t;
					if(c[k]!=c[i]){
//						for(int j=1;j<=t;j++){
//							cout<<c[k];
//						}
						ans+=t;
					}
					break;
				}
				else{
					t-=s;
					if(c[k]!=c[i]){
						ans+=s;
//						for(int j=1;j<=s;j++){
//							cout<<c[k];
//						}
					}
					s=0;
					k--;
				}
			}
			else{
				if(a[k]>t){
					s=a[k]-t;
					if(c[k]!=c[i]){
						ans+=t;
//						for(int j=1;j<=t;j++){
//							cout<<c[k];
//						}
					}
					break;
				}
				else{
					t-=a[k];
					if(c[k]!=c[i]){
						ans+=a[k];
//						for(int j=1;j<=a[k];j++){
//							cout<<c[k];
//						}
					}
					k--;
				}
			}
		}
//		cout<<"\n";
		if(sum==0){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
