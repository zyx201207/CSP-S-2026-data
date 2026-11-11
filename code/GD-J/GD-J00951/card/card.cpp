#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int k[M],a[N],f[M],l[M];
int n,m;
bool all(int e[]){
	for(int i=1;i<=m;i++)if(!e[i])return false;
	return true;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[a[i]]++;
	}
	k[a[n]]=n;
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i]){
				f[a[i]]=j;
				break;
			}
		}
		if(all(f))break;
	}
	l[a[n]]++;
	for(int i=n-1;i>=1;i--){
		if(l[a[i]])continue;
		if(all(l))break;
		l[a[i]]++;
		for(int j=i;j<=n;j++){
			k[a[i]]+=(i-f[a[j]]-1);
		}
	}
	for(int i=1;i<=m;i++)cout<<k[i]<<" ";
	return 0;
}
