#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+7;
struct node{
	long long sum;
	char c;
}a[N];
long long n,pre[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s="";
	cin>>n;
	long long num=0;
	for(long long i=1;i<=n;i++)
	{
		
		cin>>a[i].sum>>a[i].c;
		num+=a[i].sum;
		a[i].sum+=a[i-1].sum;
	}
	long long ans=0;
	for(long long i=1,j=num,i_op=1,j_op=n;;)
	{
//		cout<<i<<" "<<j<<" "<<a[i_op].sum-i+1<<" "<<j-a[j_op-1].sum<<" "<<ans<<endl;
		if(i>=j||i_op==j_op)
		{
			break;
		}
		if(a[i_op].sum-i+1>j-a[j_op-1].sum)
		{
			if(a[i_op].c!=a[j_op].c)
			{
				ans+=j-a[j_op-1].sum;
			}
			j_op--;
			i+=j-a[j_op].sum;
			j=a[j_op].sum;
		}
		else if(a[i_op].sum-i+1<j-a[j_op-1].sum)
		{
			if(a[i_op].c!=a[j_op].c)
			{
				ans+=a[i_op].sum-i+1;
			}
			j-=a[i_op].sum-i+1;
			i=a[i_op].sum+1;
			i_op++;
		}
		else
		{
			if(a[i_op].c!=a[j_op].c)
			{
				ans+=a[i_op].sum-i+1;
			}
			j_op--;
			i=a[i_op].sum+1;
			j=a[j_op].sum;
			i_op++;
		}
	}
	cout<<ans;
	return 0;
}
