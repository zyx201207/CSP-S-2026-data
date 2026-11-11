#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,st;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		if(m<0){
			st++;
			m+=(a[i]-a[st]);
		}ans=max(ans,i-st);
		m-=(i-st)*(a[i]-a[i-1]);
	}cout<<ans;
	return 0;
}