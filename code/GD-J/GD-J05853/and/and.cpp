#include<bits/stdc++.h>
using namespace std;
long long n,m,st;
long long a[200005];
long long yhhmx[200005];
long long cnt[5];
void jiqi(long long x,long long t,long long yhh){
	if(t==m){
		yhhmx[st]=max(yhhmx[st],yhh);
		return;
	}
	for(long long i=x;i<=n;i++){
		cnt[t+1]=a[i];
		long long nw=a[i];
		long long k= yhh & nw ;
		jiqi(i+1,t+1,k);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=-1;
	for(long long i=1;i<=n-m+1;i++){
		st=i;
		cnt[1]=a[i];
		jiqi(i+1,1,a[i]);
		ans=max(ans,yhhmx[i]);
	}
	cout<<ans;
}
