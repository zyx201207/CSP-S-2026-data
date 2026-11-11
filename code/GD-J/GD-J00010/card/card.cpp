#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
ll n,m,a[500005],s[300005],b[500005],c[500005],r;
bool v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	for(ll i=1;i<=n;++i){
		r=n;
		for(ll j=i;j<=n;++j){
			b[j-i+1]=a[j];
			v[b[j-i+1]]=0;
			c[b[j-i+1]]=0;
		}
		for(ll j=i;j<=r;++j){
			if(v[b[j-i+1]]==0){
				v[b[j-i+1]]=1;
				c[b[j-i+1]]=j-i+1;
			}else{
				for(ll k=c[b[j-i+1]]+1;k<j-i+1;++k){
					v[b[k]]=0;
					b[k]=0;
				}
				b[j-i+1]=0;
			}
		}
		for(ll j=i;j<=r;++j){
			++s[b[j-i+1]];
		}
	}
	for(ll i=1;i<=m;++i){
		cout<<s[i]<<" ";
	}
	return 0;
} 
