#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],st,ed,stp=1,edp;
long long tot1,tot2,pre[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
	}
	edp=n;
	st=1;ed=n;
	for(long long i=1;i<=pre[n]/2;i++){
		tot1++;
		tot2++;
		if(tot1>a[st]){
			tot1-=a[st];
			st++;
			stp++;
		}
		if(tot2>a[ed]){
			tot2-=a[ed];
			ed--;
			edp--;
		}
		if(c[stp]!=c[edp]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

