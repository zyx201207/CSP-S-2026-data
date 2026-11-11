#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    string a;
	for(int i=1;i<=n;i++)
	{
		int b;
		char c;
		cin>>b>>c;
		for(int j=1;j<=b;j++)
		{
		    a+=c;
		}     
		
	}//此时字符串已输入完毕
	int ans=0;	
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=a[a.size()-1-i])
		{
			ans++;
		}
	} 
	cout<<ans/2;
	return 0;
}
