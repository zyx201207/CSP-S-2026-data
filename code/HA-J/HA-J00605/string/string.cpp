#include<bits/stdc++.h>
using namespace std;
long long n,a[214514],ans;
char s[214514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{	cin>>a[i];
		cin>>s[i];
	}
	for(int i=1,j=n;i<j;)
	{	if(s[i]!=s[j])
		{	if(a[i]>=a[j])
			{	ans+=a[j];
				a[i]-=(a[i]-a[j]);
				j--;
			}
			else 
			{	ans+=a[i];
				a[j]-=(a[j]-a[i]);
				i++;
			}
		}
		else 
		{	if(a[i]>=a[j])
			{	a[i]-=(a[i]-a[j]);
				j--;
			}
			else 
			{	a[j]-=(a[j]-a[i]);
				i++;
			}
		}
		if(i==j) break;
	}
	cout<<ans;
	return 0;
}
