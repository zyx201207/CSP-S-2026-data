//GZ-J00216 敖德钦 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,x,c,p;
string s,s1,s2;
int main()
{  
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int o=1;o<=n;o++)
	{
		cin>>m>>s;
		for(int i=1;i<=m;i++)
		{
			s2+=s;
		}
	}
	
	for(int i=0;i<=s2.size()/2;i++)
	{
		if(s2[s2.size()-i-1]!=s2[i]){
			x++;
		}
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

