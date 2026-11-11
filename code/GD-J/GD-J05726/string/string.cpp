#include<bits/stdc++.h>
using namespace std;
string str;
long long n,a,ans;
char b;
void arr(int a)
{
	int l=0,r=a-1;
	while(l<=r)
	{
		if(str[l]!=str[r])ans++;
		l++,r--;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=0;j<a;j++)
			str+=b;
	}
	arr(int(str.size()));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
