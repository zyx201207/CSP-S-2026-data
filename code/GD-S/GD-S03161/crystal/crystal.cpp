#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,res,m,a[N],l=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0,j=0;j<n;l-=a[j]-a[i],i++){
		j=max(j,i);
		while(j<n&&l<=m) j++,l+=(a[j]-a[j-1])*(j-i);
		res=max(res,j-i);
	}
	cout<<res<<endl;
	return 0;
}
