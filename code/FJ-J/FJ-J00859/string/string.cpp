#include<bits/stdc++.h>
using namespace std;
int a,b[200005];
char c[200005];
char s[1000005];
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	long long sum=0;
	int li=1;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i]>>c[i];
		for(int j=1;j<=b[i];j++)
		{
			s[li]=c[i];
			//cout<<s[li]<<endl;
			li++;
		}
	}
	int lli=li-1;
	//cout<<endl;
	for(int i=1;i<=li/2-1;i++,lli--)
	{
		if(s[i]!=s[lli])
		{
			cnt++;
			//cout<<cnt<<" ";
		}
	}
	//cout<<endl;
	cout<<cnt;
	return 0;
}
