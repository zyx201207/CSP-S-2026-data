#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
long long f,size,ans,a[200005];
string s,s1,s2;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else
			{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else
		{
			f=min(a[r],a[l]);
			ans+=f;
			a[r]-=f;
			a[l]-=f;
			if(a[l]==0) l++;
			else r--;
		}
	}
	cout<<ans;
	return 0;
}
