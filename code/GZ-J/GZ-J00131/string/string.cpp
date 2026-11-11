//准考证号：GZ- J00131  学校：遵义市新蒲新区滨湖中学  姓名：刘睿澜
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int n,a,ans=0;
    string s,c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a>>c;
    	for(int j=1;j<=a;j++)
    	{
    		s+=c;
		}
	}
	long long int b=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[b-i-1])
		{
			ans++;
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
 } 
