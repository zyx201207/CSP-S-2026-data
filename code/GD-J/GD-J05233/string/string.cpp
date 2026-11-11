#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
int n,a[N],s;
char ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch[i];
	for(int l=1,r=n;l<=r;)
	{
		if(l==r) break;
		if(a[l]>a[r])
		{
			if(ch[l]!=ch[r]) s=s+a[r];
			a[l]=a[l]-a[r--];
		}
		else if(a[l]<a[r])
		{
			if(ch[l]!=ch[r]) s=s+a[l];
			a[r]=a[r]-a[l++];
		}
		else
		{
			if(ch[l]!=ch[r]) s=s+a[l];
			l++,r--;
		}
	}
	cout<<s; 
	return 0;
}
