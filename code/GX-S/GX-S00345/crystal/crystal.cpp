#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,S=0,M=1;
	cin>>n>>m;
	long long l[n];
	for(int i=0;i<n;i++)
	{
		scanf("%lld",l+i);
	}
	sort(l,l+n);
	for(int i=0;i+M<n;)
	{	
		S+=M*(l[i+M]-l[M+i-1]);
		if(m<S) 
		{
			
			S-=l[i+M];
			S+=l[i++];
		}
		else
		{
			M++;
		}
	}
	cout<<M;
	return 0;
}
