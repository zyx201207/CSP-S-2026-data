#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200010],a1=0,a2=0,sum=0;
	char c[200010];
	string str=" ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		a1=a[i];
		a2+=a1;
		while(a1--)
		{
			str=str+c[i];
		}
	}
	for(int i=1;i<=a2/2;i++)
	{
		long long s=a2;
		if(str[i]!=str[s+1-i])sum++;
	}
	cout<<sum;
	return 0;
}
