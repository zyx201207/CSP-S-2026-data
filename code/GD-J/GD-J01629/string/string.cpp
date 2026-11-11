#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n;
struct JG{
	ll x;
	char y;
}a[1000100];
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(ll i=1,j=n;i<j;){
		if(a[i].y!=a[j].y){
			ans+=min(a[i].x,a[j].x);
			if(a[i].x>a[j].x){
				a[i].x-=a[j].x;
				j--;
			}
			else if(a[i].x<a[j].x){
				a[j].x-=a[i].x;
				i++;
			}
			else i++,j--;
		}
		else {
			if(a[i].x>a[j].x){
				a[i].x-=a[j].x;
				j--;
			}
			else if(a[i].x<a[j].x){
				a[j].x-=a[i].x;
				i++;
			}
			else i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
