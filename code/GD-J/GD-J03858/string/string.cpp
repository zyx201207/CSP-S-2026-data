#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
long long  a[N];
string s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		cin>>s[i];
	}
	int i=1,j=n;
	while(i<=j)
	{
		if(s[i]==s[j]) 
		{
			if(a[i]>a[j]) a[i]-=a[j],j--;
			else if(a[i]<a[j]) a[j]-=a[i],i++;
			else a[i]=a[j]=0,i++,j--;
		}
		else
		{
			if(a[i]>a[j]) ans+=a[j],a[i]-=a[j],j--;
			else if(a[i]<a[j]) ans+=a[i],a[j]-=a[i],i++;
			else ans+=a[i],a[i]=a[j]=0,i++,j--;
		}
	}
	cout<<ans;
	return 0;
} 
