#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
struct nd{
	ll x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].x<a[r].x){
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}else{
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
		}else{
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				a[l].x-=a[r].x;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
