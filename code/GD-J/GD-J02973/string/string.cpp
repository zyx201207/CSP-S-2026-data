#include<bits/stdc++.h>
using namespace std;
long long n,m,t,b[100005],as,cnt=1,ct=1,ans=0,zc1=1,zc2=1;
char c[100005];
string s1,s2,c1,c2;
struct node{
	long long n;
	char c;
}a[100005],at[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>b[i]>>c[i];
		if (i==1)
		{
			a[cnt].n=b[i];
			a[cnt].c=c[i];
		}
		else
		{
			if (a[cnt].c!=c[i])
			{
				cnt++;
				a[cnt].n=b[i];
				a[cnt].c=c[i];
			} 
			else
			{
				a[cnt].n+=b[i];
			}
		}
		as+=b[i];
	}
	t=as/2;
	for (int i=cnt;i>=1;i--)
	{
		if (i==cnt && a[i].n<=t)
		{
			at[ct].n=a[i].n;
			at[ct].c=a[i].c;
			t-=a[i].n;
		}
		else if (a[i].n<t)
		{
			ct++;
			at[ct].n=a[i].n;
			at[ct].c=a[i].c;
			t-=a[i].n;
		}
		else if (t!=0)
		{
			ct++;
			at[ct].n=t;
			at[ct].c=a[i].c;
			t=0;
		}
	}
	t=as/2;
	while (at[ct].n!=0)
	{
		if (a[zc1].c!=at[zc2].c)
		{
			if (a[zc1].n>at[zc2].n){
				ans+=at[zc2].n;
				a[zc1].n-=at[zc2].n;
				at[zc2].n=0;
				zc2++;
			}
			else if (a[zc1].n<at[zc2].n){
				ans+=a[zc1].n;
				at[zc2].n-=a[zc1].n;
				a[zc1].n=0;
				zc1++;
			}
			else if (a[zc1].n=at[zc2].n){
				ans+=a[zc1].n;
				at[zc2].n=0;
				a[zc1].n=0;
				zc1++;
				zc2++;
			}
		}
		else
		{
			if (a[zc1].n>at[zc2].n){
				a[zc1].n-=at[zc2].n;
				at[zc2].n=0;
				zc2++;
			}
			else if (a[zc1].n<at[zc2].n){
				at[zc2].n-=a[zc1].n;
				a[zc1].n=0;
				zc1++;
			}
			else if (a[zc1].n=at[zc2].n){
				at[zc2].n=0;
				a[zc1].n=0;
				zc1++;
				zc2++;
			}
		}
	}
	cout<<ans;
	
	/*µ÷ÊÔÓÃ 
	for (int i=1;i<=cnt;i++)
	{
		cout<<a[i].n<<a[i].c<<"\n";
	}
	for (int i=1;i<=ct;i++)
	{
		cout<<at[i].n<<at[i].c<<"\n";
	}
	cout<<as;*/
	 
	
	return 0;
}
//6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b

