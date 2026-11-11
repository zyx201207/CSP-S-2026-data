#include <bits/stdc++.h>
using namespace std;
int get(string s)
{
	if(s[2]<='D')
		return s[2]-'A';
	else
		return 4;
}
bool near(int a,int b)
{
	if(0<=a&&a<=2&&0<=b&&b<=2||3<=a&&a<=4&&3<=b&&b<=4)
		return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int k1=(s1[0]-'0')*10+s1[1]-'0',k2=(s2[0]-'0')*10+s2[1]-'0',r1=get(s1),r2=get(s2);
	cout<<(c1==c2)<<(c1==c2&&k1==k2)<<(c1==c2&&k1==k2&&near(r1,r2))<<(c1==c2&&k1==k2&&near(r1,r2)&&abs(r1-r2)==1);
	return 0;
}//O(1),AC
