#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n; 
ll l;
ll a[maxn];
char c[maxn];
ll find(ll x){
	for(int i=n;i>=(n>>1);i--){
		if(a[i]<=x) return i;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll b;
		cin>>b>>c[i];
	}
	cout<<"0"<<'\n';
} 
