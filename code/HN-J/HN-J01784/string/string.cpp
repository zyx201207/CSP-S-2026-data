#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long int sum=0;
	for(int i=1;i<=n;i++)
	{
		int a1;
		cin>>a1;
		char c;
		cin>>c;
		for(int j=1;j<=a1;j++)
		{
			sum++;
			s[sum]=c;
		}
	}
	if(n==1)
	{
		cout<<0;
	}else{
		int js=0;
		if(sum%2==0)
		{
			js=sum/2;
		}else{
			js=sum/2+1;
		}
		long long int bj=0;
		long long int ls=sum;
		for(int i=1;i<=js;i++)
		{
			if(s[i]!=s[ls]){
				bj++;
			} 
			ls--;
		}
		if(bj==0)
		{
			cout<<0;
		}else{
			cout<<bj;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
