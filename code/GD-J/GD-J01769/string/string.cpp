#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],p1,p2,k;
char c[N];
string l;
long long sum,num1,num2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	p1=1;
	p2=n;
	num1=a[1];
	num2=a[n];
	while(p1<p2)
	{
		//cout<<num1<<" "<<num2<<" "<<k<<"\n";
		if(num1<num2)
		{
			if(c[p1]!=c[p2]) sum+=num1-k;
			k=num1;
			p1++;
			num1+=a[p1];
		}
		else if(num1>num2)
		{
			if(c[p1]!=c[p2]) sum+=num2-k;
			k=num2;
			p2--;
			num2+=a[p2];
		}
		else
		{
			if(c[p1]!=c[p2]) sum+=num1-k;
			k=num1;
			p1++;
			p2--;
			num1+=a[p1];
			num2+=a[p2];
		}
	}
	cout<<sum;
}
