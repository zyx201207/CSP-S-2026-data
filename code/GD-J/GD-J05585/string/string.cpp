#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char s[200005];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++)
		{
			b+=s[i];
		}
	}
	for(int i=0,j=b.size()-1;i<=j;i++,j--)
	{
		if(b[i]!=b[j])ans++;
	}
	cout<<ans;
	return 0;
}
