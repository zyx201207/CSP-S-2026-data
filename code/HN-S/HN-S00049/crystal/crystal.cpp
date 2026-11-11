#include<bits/stdc++.h>
using namespace std;
	long long n,m,ans,a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		double sum=m;
		bool b=1;
		for(int j=1;j<=i;j++) sum+=a[j];
		sum/=i;
		for(int j=1;j<=i;j++){
			if(sum<a[j]) b=0;
		}
		if(ans<i&&b) ans=i;
	}
	cout<<ans;
	return 0;
}
