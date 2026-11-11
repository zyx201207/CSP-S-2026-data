#include <bits/stdc++.h>
using namespace std;

const long long _5e5=5e5+50;
long long N,M,P,A[_5e5],L[_5e5],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>N>>M;
	for(long long a=1;a<=N;a++)
	{
		cin>>A[a];
	}
	sort(A+1,A+1+N);
	long long p=1;
	P=N;
	for(long long a=1;a<=N;a++)
	{
		if(a==1)
		{
			L[a]=1;
		}
		else if(A[a]==A[p])
		{
			P--;
			L[p]++;
		}
		else if(A[a]!=A[p])
		{
			p++;
			L[p]=1;
			A[p]=A[a];
		}
	}
	long long cnt=-1;
	for(long long a=1;a<=P;a++)
	{
		long long tem=(L[a]*(A[a+1]-A[a]));
		if(tem>M)
		{
			L[a+1]+=M/(A[a+1]-A[a]);
			cnt=a+1;
			break;
		}
		L[a+1]+=L[a];
		M-=tem;
		if(M==0)
		{
			cnt=a+1;
			break;
		}
	}
	cout<<L[cnt]<<endl;
	return 0;
}
