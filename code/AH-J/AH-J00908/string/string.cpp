#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n,sum=0;
	while(l < r){
		if(c[l] == c[r]){
			if(a[l] > a[r]){
				r -- ;
				a[l] -= a[r+1];
			}else if(a[l] == a[r]){
				l ++ ;
				r -- ;
			}else{
				l ++ ;
				a[r] -= a[l-1];
			}
		}else{
			if(a[l] > a[r]){
				sum += a[r];
				r -- ;
				a[l] -= a[r+1];
			}else if(a[l] == a[r]){
				sum += a[l];
				l ++ ;
				r -- ;
			}else{
				sum += a[l];
				l ++ ;
				a[r] -= a[l-1];
			}
		}
	}
	cout<<sum;
	return 0;
}
