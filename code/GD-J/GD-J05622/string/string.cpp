#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long M=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=M;
		}
		a[l]-=M;
		a[r]-=M;
		if(!a[l]) l++;
		if(!a[r]) r--;
//		cerr<<l<<' '<<r<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
