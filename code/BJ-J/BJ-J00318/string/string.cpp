#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],s[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	ll x=0,mid=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		s[i]=x+1;
		x+=a[i];
	}
	ll ans=0;
	int k;
	if(x%2){
		mid=1ll*(x+1)/2;
		for(k=1;k<=n;k++)
			if(mid>=s[k]&&mid<s[k+1]) break;
		a[k]--;
		for(int i=1,j=n;i<=k && j>=k;i++,j--){
			if(c[i]==c[j]){
				if(a[i]>a[j]){
					i--;
				}
				else if(a[i]<a[j]){
					j++;
				}
				else continue;
			}
			else{
				if(a[i]>a[j]){
					ans+=a[j];
					i--;
				}
				else if(a[i]<a[j]){
					ans+=a[i];
					j++;
				}
				else continue;
			}
		}
		cout<<ans;
	}
	else{
		mid=1ll*x/2;
		for(k=1;k<=n;k++)
			if(mid>=s[k]&&mid<s[k+1]) break;
		for(int i=1,j=n;i<=k && j>=k;i++,j--){
			if(c[i]==c[j]){
				if(a[i]>a[j]){
					i--;
				}
				else if(a[i]<a[j]){
					j++;
				}
				else continue;
			}
			else{
				if(a[i]>a[j]){
					ans+=a[j];
					i--;
				}
				else if(a[i]<a[j]){
					ans+=a[i];
					j++;
				}
				else continue;
			}
		}
		cout<<ans;
	}
	return 0;
}
