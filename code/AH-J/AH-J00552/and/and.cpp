#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=(1LL<<32),ans=0;
	for(int i=31;i>=0;i--){
		x/=2;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&(ans+x))==ans+x)cnt++;
		}
		//cout<<ans+x<<" "<<cnt<<"\n";
		if(cnt>=m){
			ans+=x;
		}
	}
	cout<<ans;
	return 0;
}
