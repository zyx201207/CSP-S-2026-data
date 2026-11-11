#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],l=1,r,s;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<=r)
	{
		if(c[l]==c[r])	
		{
			if(a[l]<a[r])  a[r]-=a[l],l++;
			else  if(a[l]==a[r])  l++,r--;
			else  a[l]-=a[r],r--;
		}
		else
		{
			if(a[l]<a[r])  s+=a[l],a[r]-=a[l],l++;
			else  if(a[l]==a[r])  s+=a[l],l++,r--;
			else  s+=a[r],a[l]-=a[r],r--;
		}
	} 
	cout<<s;
	return 0;
}
