#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int sum=0;
	cin>>n;
	string c;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}	
	for(int i=n;i>=a[i];i--)
	{
		if(c[1]!=c[i])
		{
			sum+=a[i];
		}
		
	}	
	
	cout<<sum;
	
	 
	 return 0;
}

