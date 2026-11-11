#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll const N=2e5+5;
struct c{
	ll len;
	string s;
};
c a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].s;
	}
	ll l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[l].s!=a[r].s){
			ans+=min(a[l].len,a[r].len);
		}
		if(a[l].len>a[r].len){
			a[l].len-=a[r].len;
			r--;
		}else if(a[l].len<a[r].len){
			a[r].len-=a[l].len;
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
