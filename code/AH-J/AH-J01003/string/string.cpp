#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+10;
struct Node{
	ll x;
	string y;
}a[N];
ll n,cnt=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	ll r=0;
	for(ll i=1;i<=n/2;i++){
		if(a[i].y!=a[n-i-1+r].y){
			if(a[i].x==a[n-i-1+r].x){
				cnt+=a[i].x;
			}else if(a[i].x<a[n-1-i+r].x){
				cnt+=a[i].x;
				a[n-i+r].x-=a[i].x;
				r++;
			}else{
				cnt+=a[n-i+r-1].x;
				a[i].x-=a[n-i+r-1].x;
				i--;
				n--;
			}
		}else if(a[i].y==a[n-i-1+r].y){
			if(a[i].x<a[n-i+r].x-1){
				a[n-i+r-1].x-=a[i].x;
				r++;
			}else{
				a[i].x-=a[n-1-i+r].x;
				i--;
				n--;
			}
			
		}
	}
	cout<<cnt;
	return 0;
}
