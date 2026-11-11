#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int n;
int arr[30]={0};
int cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=30;i++)
	arr[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		int b=c[i]-'a'+1;
		if(arr[b]==0)
		{
			arr[b]=1;
			cnt++;
		}
	}
	if(cnt==1)
	{
		cout<<0;
	}
	else
	cout<<n/2;
}
