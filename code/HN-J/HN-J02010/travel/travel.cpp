#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
//	freopen("travel.in","r",stdout);
//	freopen("travel.out","w",stdin);
//	freopen("travel.in","w",stdin);
//	freopen("travel.out","r",stdout);
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool b1=c1==c2,b2=b1&&s1[0]==s2[0]&&s1[1]==s2[1],b3=b2&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'),b4=b3&&(abs(s1[2]-s2[2])==1);
	cout<<b1<<b2<<b3<<b4;
	return 0;
} 
//我要上迷惑行为大赏！！！ 
//关注洛谷 __Amnesia_search__ 谢谢喵。 
