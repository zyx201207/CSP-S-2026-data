#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int n,m,sum,ans;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>c;
		for(int j=sum;j<sum+m;j++) a[j]=c;
		sum+=m;  
	}
	//for(int i=0;i<sum;i++) cout<<s[i];//Ðè×¢ÊÍ 
	int b=(sum-1)/2+1;
	//cout<<b;//Ðè×¢ÊÍ 
	if(sum%2==1)
	{
		for(int i=0;i<b-1;i++)
			if(a[i]!=a[sum-i-1]) ans++;
	}
	else
	{
		for(int i=0;i<=b-1;i++)
			if(a[i]!=a[sum-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}

