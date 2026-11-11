#include<bits/stdc++.h>
using namespace std;
char str[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	char letter[n];
	long long temp;
	int i;//¡Ÿ ± 
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>letter[i];
		temp+=a[i];
		for(int j=temp;j>temp-a[i];j--)
		{
			str[j-1]=letter[i];
		}
	}
	long long cishu;
	for(i=0;i<temp/2;i++)
	{
		if(str[i] != str[temp-i-1])
		{
			cishu+=1;
		}
	}
	cout<<cishu;
}
