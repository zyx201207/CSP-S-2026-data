#include<bits/stdc++.h>
#define ll long long
#define itn int
using namespace std;
const int N=3e5+5;
int n;
ll a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	ll ans=0;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				l++;
				r--;
			}
			continue;
		}else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
