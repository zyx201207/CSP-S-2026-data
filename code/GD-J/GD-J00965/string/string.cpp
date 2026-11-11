#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin >> b[i];
	}
	for(int i=1,j=n;i<=j;)
	{
		if(b[i]==b[j])
		{
			if(a[i]>a[j]) 
			{
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else
			{
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
		else{
			if(a[i]>a[j]) 
			{
				a[i]-=a[j];
				sum+=a[j]; 
				a[j]=0;
				j--;
			}
			else
			{
				a[j]-=a[i];
				sum+=a[i]; 
				a[i]=0;
				i++;
			}
		}
		
	}
	printf("%lld",sum);
	return 0;
}

