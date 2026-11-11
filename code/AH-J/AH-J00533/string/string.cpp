#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,l,r,b[200005],s;
string a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(0)
	//cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
	}
	r=n;
	l=1;
	while(l<r)
	{
		if(a[l]==a[r])
		{
			m=min(b[l],b[r]);
			b[l]-=m;
			b[r]-=m;
		}
		else
		{
			if(b[l]>=b[r])
			{
				s+=b[r];
				b[l]-=b[r];
				b[r]=0;
				//cout<<s<<' '<<r<<" 1"<<'\n';
			}
			else
			{
				s+=b[l];
				//cout<<s<<' '<<l<<" 2"<<'\n';
				b[r]-=b[l];
				b[l]=0;
			}
		}
		if(b[l]==0) l++;
		if(b[r]==0) r--;
		if(l==r) break;
		//cout<<l<<' '<<r<<' ';
	}
	cout<<s;
}
