#include <iostream>
using namespace std;
long long sum;
int n,a[200005];
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	//
	for(int i=1;i<=n;i++)
	{
		if(c[i]==c[n-i])
		{
			continue;
		}else{
			break;
		}
		if(i==n)
		{
			cout<<0;
			return 0;
		}
	}
	//
	for(int i=1;i<=n/2;i++)
	{
		if((a[i]==a[n-i])&&(c[i]!=c[i-1]))
		{
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i];
			}
		}
	}
	cout<<sum;
	return 0;
}
