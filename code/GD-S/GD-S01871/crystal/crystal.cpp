#include<bits/stdc++.h>
using namespace std;
long long k[500050],f[500050],b[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	sort(k+1,k+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+k[i];
	}
	long long l=1,r=1,maxn=-1;
	while(r<=n){
		if(1LL*(f[r]-f[l-1]+m)>=1LL*(k[r]*(r-l+1))){
			maxn=max(maxn,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<maxn;
	return 0;
}
