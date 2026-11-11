#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
	ll x;
	char ch;
}a[400000];
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].ch;
	}
	ll l=1,r=n,ans=0;
	while(l<r){
		if(a[l].ch==a[r].ch){
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				a[l].x=0;
				l++;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				a[r].x=0;
				r--;
			}
			else{
				a[l].x=a[r].x=0;
				l++;
				r--;
			}
		}
		else{
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				ans+=a[l].x;
				a[l].x=0;
				l++;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				ans+=a[r].x;
				a[r].x=0;
				r--;
			}
			else{
				ans+=a[l].x;
				a[l].x=a[r].x=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
