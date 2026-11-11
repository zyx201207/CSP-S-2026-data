#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,ans;
ll a[200005];
char c[200005];
ll l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	ll cnt=0;
	r=n-1;
	while(l<r){
		cnt=a[l];
		while(cnt){
			if(c[l]!=c[r]){
				if(cnt==a[r]){
					ans+=a[r];
					l++;
					r--;
					cnt=0;
				}
				else if(cnt>a[r]){
					cnt-=a[r];
					ans+=a[r];
					r--;
				}
				else{
					a[r]-=cnt;
					ans+=cnt;
					cnt=0;
					l++;
				}
			}
			else{
				if(cnt==a[r]){
					l++;
					r--;
					cnt=0;
				}
				else if(cnt>a[r]){
					cnt-=a[r];
					r--;
				}
				else{
					a[r]-=cnt;
					cnt=0;
					l++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
