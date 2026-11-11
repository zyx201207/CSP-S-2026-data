#include<iostream>
using namespace std;
int n,a,sum,b=0;string str,str1,s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		for(int j=1;j<=a;j++)
		{
			str+=s;
		}
	}
	b=str.size();
	for(int i=0;i<b/2;i++)
	{
		if(str[i]!=str[b-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
    return 0;
}
