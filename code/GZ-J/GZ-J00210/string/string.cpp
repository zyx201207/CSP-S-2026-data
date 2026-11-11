//GZ-J00210 ∫Î“„÷–—ß —Ó∫∆”Ó 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[200010];
char s[200010]; 
ll cmp(ll a,ll b){
	if(a<b) return a;
	else return b;
	if(a==b) return a;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,cnt=0;
	cin>>n;
	bool is=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(ll i=1,j=n;i<=n/2,j>n/2;i++,j--){
		if(s[i]==s[j]){
			i=cmp(a[i],a[j])+1;
			j-=cmp(a[i],a[j])-1;
		} 
		if(s[i]!=s[j]){
		cnt+=cmp(a[i],a[j]);
	}
	}
	cout<<cnt;
	return 0;
} 

