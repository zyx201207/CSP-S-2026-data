#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[100001],s[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<n;i++){
		bool f[100001];
		ll t[100001],k=0;
		memset(f,0,sizeof f);
		memset(t,0,sizeof f);
		for(int j=i;j<n;j++){
			if(f[j]==0)t[k]=a[j],k++,f[j]=1;
			else{
				for(k;k>=0;k--){
					if(t[k]!=a[j])t[k]=0,f[k]=0;
					else break;
				} 
				k++;
			}
		} 
		for(int j=0;j<k;j++)s[t[j]-1]++;
	}
	for(int i=0;i<m;i++)cout<<s[i]<<" ";
	return 0;
} 
