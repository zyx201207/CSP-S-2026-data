#include <bits/stdc++.h>

using namespace std;
long long n,a[200005],ans,nl,nr,sum;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int L=1,R=n;nl+nr<=sum;L++)
	{
		nl+=a[L];
		long long bnl=a[L];
		while(bnl!=0)
		{
			long long k=min(bnl,a[R]);
			nr+=k;
			bnl-=k;
			if(c[L]!=c[R]){ans+=k;}
			a[R]-=k;
			if(a[R]==0){R--;}
		}
	}
	cout<<ans;
	return 0;
}

