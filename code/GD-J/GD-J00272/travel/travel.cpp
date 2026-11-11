#include <bits/stdc++.h>
using namespace std;
using st=string;
static bool yice(st s1,st s2){
	char a=s1[2],b=s2[2];
	bool flag=(a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C');
	bool flag2=(a=='D'||a=='E')&&(b=='D'||b=='E');
	return flag||flag2;
}
static bool numeq(st s1,st s2){
	return s1[0]==s2[0]&&s1[1]==s2[1];
}
st c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2) {
		cout<<"0000";
		return 0;
	}
	cout<<1<<numeq(s1,s2)<<(yice(s1,s2)&&numeq(s1,s2));
	if (!yice(s1,s2)||!numeq(s1,s2)) {cout<<0;}
	else{
		int a=s1[0]*10+s1[1],b=s2[0]*10+s2[1];
		if (a==b&&abs(s1[2]-s2[2])==1) cout<<1;
		else if (abs(a-b)==1&&s1[2]==s2[2]) cout<<1;
		else cout<<0;
	}
	return 0;
}

