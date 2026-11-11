#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,sum,p,l=1,r,s[N];
char a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) cin>>s[i]>>a[i];
	while(l<=r){
		if(!s[l]) l++;
		if(!s[r]) r--;
		int x=s[l],y=s[r];
		if(l==r) break;
		if(a[l]!=a[r]) sum+=min(x,y);
		s[r]=max(p,y-x);
		s[l]=max(p,x-y);
	}
	cout<<sum;
	return 0;
}
