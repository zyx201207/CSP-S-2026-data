#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long s=a[1],s2=a[n];
	for(int l=1,r=n;l<r;)
	{
		if(c[l]!=c[r]) ans+=min(s,s2);
		if(s<s2)
		{
			s2=s2-s,s=0;
			l++,s+=a[l];
		}
		else if(s>s2)
		{
			s=s-s2,s2=0;
			r--,s2+=a[r];
		}
		else 
		{
			s=0,s2=0;
			l++,r--,s+=a[l],s2+=a[r];
		}
	}
	cout<<ans;
	return 0;
} 
