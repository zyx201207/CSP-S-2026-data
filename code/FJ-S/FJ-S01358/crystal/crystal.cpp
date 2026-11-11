#include<bits/stdc++.h>
using namespace std;
long long a[500005],d[500005],ans,summ,mxa;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) d[i]=a[i]-a[i-1];
	int l=1,r=1;
	while(1){
		if(summ<=m){
			r++;
			summ+=(r-l)*d[r];
		}
		if(summ>m){
			l++;
			summ-=a[r]-a[l-1];
		}
		if(r>=n) break;
		ans=r-l+1;
		mxa=max(ans,mxa);
	} cout<<mxa;
	return 0;
}
