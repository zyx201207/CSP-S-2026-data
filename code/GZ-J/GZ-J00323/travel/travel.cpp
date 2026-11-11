//GZ-J00323 遵义航天实验中学 杨熙晨 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool same_car=0,same_pai=0,same_w=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
	same_car=1;
	cout<<1;
	}
	else cout<<0;
	if(same_car&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
	same_pai=1;
	cout<<1;	
	}
	else cout<<0;
	if(same_pai&&(s1[2]<='C'&&s2[2]<='C')||('D'<=s1[2]&&'D'<=s2[2]))
	{
	same_w=1;
	cout<<1;
	}
	else cout<<0;
	if(same_w&&abs((s2[2]-'0')-(s1[2]-'0'))==1) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
