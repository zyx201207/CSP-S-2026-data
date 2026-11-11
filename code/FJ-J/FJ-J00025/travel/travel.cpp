#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char a=s1[2],b=s2[2];
			if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F'))){
				cout<<1;
				if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}/*
这题显然只要模拟即可，但CCF你出的 T1码量居然是第2，
我T2 20分钟就做完了，T1则花了15分钟，
应该是O(1)的
T1belike:5分钟完成读题以及第一版代码(shishan)，
10分钟观察（||，&&，（））有没有写错或写漏，
判断坐位是否在同一侧与是否相邻的语句有没有写漏
以及想看看能不能上迷惑行为大赏
//freopen
feropen
freopen("travel.out","r",stdin);
freopen("travel.ans","w",stdout);
freopen("travle.in","r",stdin);
CCF CCF CCF CCF CCF CCF CCF CCF CCF CCF 
(认真诈骗ing)
*/
