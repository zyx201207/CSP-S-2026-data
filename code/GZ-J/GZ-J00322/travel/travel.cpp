//GZ-J00322	  遵义市新蒲新区滨湖中学 王海涛 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="1100";
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			ans[0]='0';
		}
	}
	if(ans[0]=='1')
	{
		for(int i=0;i<=1;i++)
		{
			if(s1[i]!=s2[i])
			{
			ans[1]='0';
			}
		}
		if(ans[1]=='1')
		{
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))
			{
				ans[2]='1';
			}
			if(ans[2]=='1'&&(s1[2]+1==s2[2]||s2[2]+1==s1[2]))
			{
				ans[3]='1';
			}
		}
	}else{
		ans="0000";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

