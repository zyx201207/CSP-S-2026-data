#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		long long X=x*a[i+x-1],Y=s[i+x-1]-s[i-1];
		if(X-Y<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,md,ans=0;
	while(l<r){
		md=(l+r)/2;
		if(check(md)){
			l=md+1;
			ans=md;
		}else{
			r=md;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
