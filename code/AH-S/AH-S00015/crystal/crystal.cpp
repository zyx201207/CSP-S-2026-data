#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int l=n;l>=1;l--){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			int sum=l*a[j]-s[j]+s[i-1];
			//cout<<sum<<" "<<i<<" "<<j<<"\n";
			if(sum<=m){
				cout<<l;
				return 0;
			}
		}
	}
	return 0;
}
