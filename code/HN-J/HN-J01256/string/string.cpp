#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
const int M=1e9+10;
ll n;
struct str{
	ll l;
	char x;
	ll s,o;
}a[N];
char s[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll n_l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].x;
		a[i].s=a[i-1].o+1;
		a[i].o=a[i].s+a[i].l-1;
		n_l+=a[i].l;
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i].s;j<=a[i].o;j++){
			s[j]=a[i].x;
		}
	}
	ll ans=0;
	for(int i=1;i<=n_l/2;i++){
		if(s[i]!=s[n_l-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
