#include<bits/stdc++.h>
using namespace std;
long long sum[200005],sum2[200005],summ;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt1=0,cnt2=0;
	long long a[n+1];char c[n+1],c1[n+1];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		summ+=a[i];c1[i]=c[i];
	}
	if(summ<=100000000)
	{
		string ms;
		for(int i=1;i<=n;i++)
		{
			string s(a[i],c[i]);
			ms+=s;
		}int cnt=0;
		string ms1=ms;
		reverse(ms1.begin(),ms1.end());
		for(int i=0;i<ceil(ms.size()/2.0);i++)
		{
			if(ms1[i]!=ms[i])cnt++;
		}
//		cout<<"GG\n";
		cout<<cnt<<endl;
		return 0;
	}
	for(long long i=n;i>=1;i--)sum2[i]=sum2[i+1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		long long l=sum[i],r=sum[i-1],cnt=0;
		long long left=upper_bound(sum+1,sum+n+1,summ-l)-sum,right=lower_bound(sum+1,sum+n+1,summ-r)-sum;
//		cout<<summ-l<<" "<<summ-r<<" "<<left<<" "<<right<<endl;
		for(long long j=left;j<=right;j++)
		{
			if(c[j]!=c[i])
			{
				cnt+=max(0ll,min({sum[j]-summ+l,a[j],summ-r-sum[j-1]}));
				c[j]=c[i];
			}
//			cout<<cnt<<endl; 
		}
		
		cnt1+=cnt;
	}
	for(int i=1;i<=n;i++)c[i]=c1[i];
	for(long long i=n;i>=1;i--)
	{
		long long l=sum[i],r=sum[i-1],cnt=0;
		long long left=upper_bound(sum+1,sum+n+1,summ-l)-sum,right=lower_bound(sum+1,sum+n+1,summ-r)-sum;
//		cout<<summ-l<<" "<<summ-r<<" "<<left<<" "<<right<<endl;
		for(long long j=left;j<=right;j++)
		{
			if(c[j]!=c[i])
			{
				cnt+=max(0ll,min({sum[j]-summ+l,a[j],summ-r-sum[j-1]}));
				c[j]=c[i];
			}
//			cout<<cnt<<endl; 
		}
		
		cnt2+=cnt;
	}
	cout<<min(cnt1,cnt2)/2<<endl;
	return 0;
}
/*
T2 string 68+eps/100
我咋啥都不会。
好像假了。
服了。
8:45~10:45
感觉得绿。 
思路：显而易见。 
*/
