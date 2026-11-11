#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,sum;
ll a[200005];
char c[200005];
string t1;
bool work_1()
{
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]!=a[n-i+1]||c[i]!=c[n-i+1]) return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(work_1()||n==1)
	{
		cout<<0;
		return 0;
    }
    else if(n<=2)
    {
    	cout<<min(a[1],a[2]);
    	return 0;
	}
	else if(n<=10)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				t1=t1+c[i];
			}
		}
		for(int i=0;i<t1.size()/2;i++)
		{
			if(t1[i]!=t1[n-i-1]) sum++;
		}
		cout<<sum<<" "<<t1;
	}
	return 0;
}
