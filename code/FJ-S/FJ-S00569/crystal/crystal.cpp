#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,ans=0,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=a[n];i++){
		int b=upper_bound(a+1,a+1+n,i)-a;
		long long mm=m;
		int j=b-1;
		for(;j>=1;j--){
			if(mm<0) break;
			mm-=(i-a[j]);
	//		cout<<i<<" "<<a[j]<<" "<<i-a[j]<<" "<<mm<<" "<<j<<"\n";
		}
		long long anss=b-j-2;
		if(a[b]==i) anss++;
		if(mm>=0) anss++;
		ans=max(ans,anss);
//		cout<<ans<<"\n";
//		if(anss==7) cout<<i<<"\n";
		if(i>200000){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
return 0;
}
