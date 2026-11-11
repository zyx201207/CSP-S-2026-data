#include<bits/stdc++.h>
using namespace std;
int a[10];
string st,st1,ts,ts1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a[0]=1;a[1]=1;a[2]=1;
	cin>>st>>st1>>ts>>ts1;
	if(st==ts){
		if(st1[0]==ts1[0]&&st1[1]==ts1[1]){
			if(a[int(st1[2]-'A')]==a[int(ts1[2]-'A')]){
				if(max(st1[2],ts1[2])=='C'&&min(st1[2],ts1[2])=='A')cout<<"1110";
				else cout<<"1111";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	
	return 0;
}
//我想上猎奇行为大赏
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//feropen("travel.in","r",stdin);
//froopen("travel.out","w",stdout);
//frepoen("travel.in","r",stdin);
/*
CCF orz
CCF orz
CCF orz
对不起CCF，我要退役了，不能给你送钱了（悲悲悲！） 
T4炸了 RE我爸还没给我报S，我废了，但我准备退役了，这是我第一次，也是最后一次上机大考了。
100+100+65+0=265pts，应该可以有1=
cyn我爱你！ 
*/
