#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,f[300006],w[300005],maxx=-100003;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	f[1]=w[1];
	for(ll  i=2;i<=n;i++){
		f[0]=w[i];
		for(ll j=min(m,i);j>=1;j--){
				f[j]=max(f[j],f[j-1]&w[i]);					
		}
	}
	cout<<f[m];
	return 0;
} 
