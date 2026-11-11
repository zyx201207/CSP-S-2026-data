#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		//cout<<a[i]<<" "<<c[i]<<" ";
	}
	for(int i=1,j=n;i<j;)
	{
		if(a[i]>a[j])
		{
			if(c[i]==c[j])
			{
				a[i]-=a[j];
				j--;
				
			}
			else
			{
				a[i]-=a[j];
				s+=a[j];
				j--;
			}
		}
		else
		{
			if(c[i]==c[j])
			{
				a[j]-=a[i];
				i++;
				
			}
			else
			{
				a[j]-=a[i];
				s+=a[i];
				i++;
			}
		}
	}
	cout<<s;
	return 0;
}
