#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
string c1,s1,c2,s2;
int ce(char a,char b){
	if(a=='D' && b=='F') return 1;
	if(a=='F' && b=='D') return 1;
	if(a=='A' && (b=='B' || b=='C')) return 1;
	if(a=='B' && (b=='A' || b=='C')) return 1;
	if(a=='C' && (b=='A' || b=='B')) return 1;
	return 0;
}
int ling(char a,char b){
	if(a=='D' && b=='F') return 1;
	if(a=='F' && b=='D') return 1;
	if(a=='A' && b=='B') return 1;
	if(a=='B' && (b=='A' || b=='C')) return 1;
	if(a=='C' && b=='B') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if(ce(s1[2],s2[2])) {
				cout<<"1";
				if(ling(s1[2],s2[2])) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
/*
100+48+[35,50]+0=183pts
woshifeiwu
woshiqu
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
这个也有迷惑性为大赏吗
ohno下周期中考了
但是我语文英语道法历史一个都没背
OI还要被学弟学妹单调队列 
欸，云朵！
哒哒哒哒哒，好想玩原神，云原神！
喵了个咪的我已经连歪 4次了
哎呀记不起原UID了 写崩的吧 1682428628
阿哈不歪！ 
 
考生不能在注释中写侮辱性话语、歌词、
诗词、散文等与考试无关的话语，
若有违反可能会收到取消成绩或以上处分
*/
