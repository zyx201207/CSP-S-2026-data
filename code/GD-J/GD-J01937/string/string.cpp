#include <bits/stdc++.h>
using namespace std;
long long n,ans,r,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long>num(n+1);
	vector<char>z(n+1);
	for(long long i = 1;i<=n;i++){
		scanf("%lld",&num[i]);
		cin>>z[i];
	}
	l=1;r=n;
	while(l<r){
		long long minn=min(num[l],num[r]);
		num[l]-=minn;num[r]-=minn;
		if(z[l]!=z[r]) ans+=minn;
		if(num[l]<=0){
			l++;
		}
		if(num[r]<=0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
