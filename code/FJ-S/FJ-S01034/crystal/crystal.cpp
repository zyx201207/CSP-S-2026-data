#include <bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],s,aa,l;
int k=-1,v=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=m;
	for (int i=1;i<=n;i++) cin>>a[i];
	s=a[n];
	for (int j=n;j>0;j--){
		s=a[j];
		for (int i=n;i>=1;i--)
		{
			aa=s-a[i-1];
			if(m>=aa){
				m-=aa;
				v+=1;
			}
			else break;
		}
		if(v>k)	k=v;
		v=1;
		m=l;
		n--;	
	}
	cout<<k;
	return 0;
} 
