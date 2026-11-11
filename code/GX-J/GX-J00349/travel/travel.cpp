#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool ans[5]={0};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans[1]=1;
	if(s1[1]==s2[1]&&s1[0]==s2[0])ans[2]=1;
	if((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||((s1[3]=='F'||s1[3]=='D')&&(s1[3]=='F'||s1[3]=='D'))){
		ans[3]=1;
	    if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)ans[4]=1;
	}
	for(int i=1;i<=4;i++){
		if(ans[i])cout<<1;
		else cout<<0;
	}
	return 0;
}
