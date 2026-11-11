#include<bits/stdc++.h> 
using namespace std;
int n;
long long a[200005],s[200005],t[200005],ans;
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		s[i]=t[i-1]+1;
		t[i]=a[i]+t[i-1];
	}
	long long l=1,r=n,lt=1,rt=t[n];
	while(l!=r)
	{
		if(t[l]>t[n]+1-s[r])
		{
			if(ch[l]!=ch[r])ans+=rt-s[r]+1;
			lt=t[n]-s[r]+2;
			rt=t[--r];
		}
		else
		{
			if(ch[l]!=ch[r])ans+=t[l]-lt+1;
			rt=t[n]-t[l];
			lt=s[++l];
		}
	}
	cout<<ans;
	return 0;
}
