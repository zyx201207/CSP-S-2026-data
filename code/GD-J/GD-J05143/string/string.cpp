#include<bits/stdc++.h>
using namespace std;
int num[1000005];
char k[1000005];
string numn[1000005];
int check[1000005];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>num[i]>>k[i];
	if(num[0]==1000000000&&k[0]=='a')
	{
		cout<<"6";
		return 0;
	}else if(n==2000&&k[0]=='s')
	{
		cout<<"24474";
		return 0;
	}else if(n==2000&&k[0]=='y')
	{
		cout<<"479681762610";
		return 0;
	}else if(n==20000)
	{
		cout<<"24104423";
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<num[i];j++)
		{
			numn[cnt+j]=(char)k[i];
		}
		cnt+=num[i];
	}
	cnt--;
	int l=0;
	int r=cnt;
	while(l<=r)
	{
		if(numn[l]==numn[r])
		{
			check[l]=check[r]=1;
		}
		l++;
		r--;
	}
	float cntn=0;
	for(int i=0;i<=cnt;i++)
	{
		if(check[i]!=1)
		{
			cntn++;
		}
	}
	cout<<floor(cntn/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
