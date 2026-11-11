#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,number=0,k,i,j;
	cin>>n;
	vector<long long> a(n+6);
	vector<char> c(n+6);
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	} 
	i=0;j=n-1;
	for(;;)
	{
		if(a[i]==0)
		{
			i++;
		}
		if(a[j]==0)
		{
			j--;
		}

		if(c[i]!=c[j])
		{
			k=min(a[i],a[j]);
			a[i]-=k;a[j]-=k;
			number+=k;
		}
		else
		{
			k=min(a[i],a[j]);
			a[i]-=k;a[j]-=k;
		}
		if(i>=j)
		{
			break;
		}
	}
	cout<<number;
	return 0;
}
