#include<bits/stdc++.h>
using namespace std;
string arr="";
long long int n=0;
long long int ans=0;
long long int n1=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a=0;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			arr=arr+c;
			n1++;
		}
	}
	n1--;
	for(int i=0;i<n1/2;i++)
	{
		if(arr[i]!=arr[n1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
