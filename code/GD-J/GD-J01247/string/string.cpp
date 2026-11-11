#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(long long i=1,j=n;i<j;)
	{
		if(c[i]!=c[j])
		{
			if(a[i]==a[j])sum+=a[i],i++,j--;
			else if(a[i]<a[j])sum+=a[i],a[j]-=a[i],i++;
			else sum+=a[j],a[i]-=a[j],j--;
		}
		else
		{
			if(a[i]==a[j])i++,j--;
			else if(a[i]<a[j])a[j]-=a[i],i++;
			else a[i]-=a[j],j--;
		}
	}
	cout<<sum;
	return 0;
}
