#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,a[N],m,l,r,mid,s[N],ma;
map<int,int> mp1,mp2;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  
	{
		cin>>a[i];
		mp1[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		l=0,r=i+1;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m)  r=mid;
			else  l=mid;
		}
		mp2[a[i]]++;
		ma=max(ma,i-r+1+mp1[a[i]]-mp2[a[i]]);
	}
	cout<<ma;
	return 0;
} 
