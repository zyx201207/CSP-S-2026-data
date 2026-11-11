#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,z=0,x=0;
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		z=z+a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[i]!=b[j])
				x=1;
		}
	}
	if(x==0)
		cout<<"0";
	else
		cout<<z/2;
	return 0;
}
