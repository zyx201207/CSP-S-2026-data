#include<bits/stdc++.h>
using namespace std;
//高一了还来打CSPj想要证书自己抢(bushi 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout)；
	//骗一手 
	//神秘CCF到8:32才给密码
	//祝我RP++，和xyh99
	//旁边幽默培训机构，不教怎么解zip
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=1;//幽默陷阱 ，判断是否在同一车厢/同一排
	if(c1==c2) {
		cout<<1;
	} else {
		cout<<0;
		flag=0;
	}
	int num1=0,num2=0;
	//cout<<endl;
	//cout<<s1[1]-'0'<<endl;
	//debug
	num1=((s1[0]-'0')*10)+s1[1]-'0';
	num2=((s2[0]-'0')*1)+s2[1]-'0';
	//这**电脑键盘真难用
	//cout<<num;
	//debug
	//神秘JPL动不动就外面炸了样的响铃 
	if(flag && num1==num2)cout<<1;
	else {
		cout<<0;
		flag=0;
	}
	if(flag&&(s2[2]=='A' || s2[2]=='B' ||s2[2]=='C')&&(s1[2]=='A' || s1[2]=='B' ||s1[2]=='C')) {
		cout<<1;
		if ((s2[2]+1)==s1[2] || s2[2]-1==s1[2])cout<<1;
		else cout<<0;
	} else if(flag&&(s2[2]=='D' || s2[2]=='F')&&(s1[2]=='D' || s1[2]=='F')) {
		cout<<"11";
	} else cout<<"00";
	return 0; 
	//神成功使用29min切出CSP-J T1 %%%%%% 
	//2018来除csp2019江西最水的T1今年分数线一定水涨船高
	//建议chen_zhe和kkk给这题给到入门 
	//Rp++; 
	//xyh99 
}
