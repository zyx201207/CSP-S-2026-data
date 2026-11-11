#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int l_1,l_2,p_1,p_2;
bool abc_1,abc_2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	l_1=(s_1[0]-'0')*10+(s_1[1]-'0');
	l_2=(s_2[0]-'0')*10+(s_2[1]-'0');
	abc_1=(s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C');
	abc_2=(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C');
	if(s_1[2]=='A') p_1=1;
	else if(s_1[2]=='B') p_1=2;
	else if(s_1[2]=='C') p_1=3;
	else if(s_1[2]=='D') p_1=4;
	else if(s_1[2]=='F') p_1=5;
	if(s_2[2]=='A') p_2=1;
	else if(s_2[2]=='B') p_2=2;
	else if(s_2[2]=='C') p_2=3;
	else if(s_2[2]=='D') p_2=4;
	else if(s_2[2]=='F') p_2=5;
	cout<<(c_1==c_2)<<(c_1==c_2&&l_1==l_2)<<(c_1==c_2&&l_1==l_2&&abc_1==abc_2)<<(c_1==c_2&&l_1==l_2&&abc_1==abc_2&&(p_1-p_2==1||p_1-p_2==-1));
	/*DEBUGprintf("\n%d %d %d %d %d %d",l_1,l_2,abc_1,abc_2,p_1,p_2);*/
	return 0;
}
