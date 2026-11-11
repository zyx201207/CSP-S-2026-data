#include<bits/stdc++.h>
using namespace std;
long long N;
long long A[200005];
char c[200005];
long long Ans;
long long sum3[200005],sum4[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&N);
	long long sum=0;
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&A[i]);
		cin>>c[i];
		sum+=A[i];
		sum3[i]=sum3[i-1]+A[i];
	}
	sum4[N+1]=0;
	for(int i=N;i>=1;i--)
	{
		sum4[i]=sum4[i+1]+A[i];
	}
	long long sumnow=0;

	long long ggggg=N;


	for(int i=1;i<=N;i++)
	{
		if(i>=ggggg)
		{
			break;
		}
//		cout<<i<<endl;
//		cout<<ggggg<<endl;
		if(sum4[ggggg]>=sumnow+A[i])
		{
			if(c[i]!=c[ggggg])
			{
				Ans+=A[i];
			}
			ggggg=ggggg;
			sumnow+=A[i];
			continue;
		}
		else
		{
//			cout<<"a"<<endl;
			if(c[i]!=c[ggggg])
			{
				Ans+=sum4[ggggg]-sumnow;
			}
			ggggg--;
		}
		while(sum4[ggggg]<sumnow+A[i])
		{
			if(c[i]!=c[ggggg])
			{
				Ans+=A[ggggg];
			}
			ggggg--;
		}
		if(c[i]!=c[ggggg])
		{
			Ans+=sumnow+A[i]-sum4[ggggg+1];
		}
//		cout<<i<<" "<<ggggg<<" "<<Ans<<"\n"; 
		sumnow+=A[i];		
		if(sumnow>(sum+1)/2)
		{
			break;
		}
	}
	printf("%lld",Ans);
	return 0;
}
