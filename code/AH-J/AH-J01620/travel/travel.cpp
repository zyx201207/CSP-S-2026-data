#include<bits/stdc++.h>
using namespace std;
int flag[128];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	flag['A']=flag['B']=flag['C']=114;
	flag['D']=flag['F']=514;
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
		cout<<"0000";
	else if(s2.substr(0,2)!=s4.substr(0,2))
		cout<<"1000";
	else if(flag[s2[2]]!=flag[s4[2]])
		cout<<"1100";
	else if(s2[2]-s4[2]!=1&&s2[2]-s4[2]!=-1)
		cout<<"1110";
	else cout<<"1111";
	return 0;
}
