#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string k;
	long long n,ty=0,num=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ty;
		cin>>k[num];
		for(int y=1;y<ty;y++)
		{
			k[num+y]=k[num];
		}
		num=num+ty;
		ty=0;
	}
	for(int i=0;i<num/2;i++)
	{
		if(k[i]!=k[num-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
