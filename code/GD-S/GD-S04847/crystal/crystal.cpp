#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,w[780005],f[210000005],p=INT_MIN;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(ll j=0;j<=m;j++)f[j]=1;
	sort(w+1,w+1+n);
	for(int k=n;k>=2;k--){
		for(ll j=0;j<=m;j++)f[j]=1;
		for(int i=1;i<=k-1;i++)for(ll j=m;j>=w[k]-w[i];j--)f[j]=max(f[j],f[j-w[k]+w[i]]+1);		
		if(p<f[m])p=f[m];
		if(p>=k){
			cout<<p;
			return 0; 
		}
	}
	cout<<1;
	return 0;	
} 
