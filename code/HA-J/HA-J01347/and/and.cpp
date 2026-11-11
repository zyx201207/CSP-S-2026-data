#include <bits/stdc++.h>
using namespace std;
int N,M,A[1000005],maxx,Ans,maxy;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>N>>M;
	for (int i=1;i<=N;i++)
	{
		cin>>A[i];
	}
	if (M==1)
	{
		for (int i=1;i<=N;i++)
			maxx=max(maxx,A[i]);
		cout<<maxx;
		return 0;
	}
	else if (M==2)
	{
		for (int i=1;i<N;i++)
			maxy=max(maxy,A[i]&A[i+1]);
		cout<<maxy;
		return 0;
	}
	else if (M==N)
	{
		Ans=A[1];
		for (int i=2;i<=N;i++)
			Ans&=A[i];
		cout<<Ans;
		return 0;
	}
	else
	{
		cout<<maxx;
	}
	return 0;
}

