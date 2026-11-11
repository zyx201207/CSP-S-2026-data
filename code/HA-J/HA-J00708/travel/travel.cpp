#include <bits/stdc++.h>
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

void fre(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}

bool check(char a,char b){
	if(a=='E'||a=='D')a='1';
	else a='0';
	if(b=='E'||b=='D')b='1';
	else b='0';
	return a==b;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b==d)cout<<1;
	else cout<<0;
	if(a==c&&b==d&&check(e,f))cout<<1;
	else cout<<0;
	if(a==c&&b==d&&check(e,f)&&max((int)e,(int)f)-min((int)e,(int)f)!=2)cout<<1;
	else cout<<0;




	Luogu _DEQUE_;
}//172.16.12.5
//remember to check your code,you didn't use "define int long long" or "fre()"
//绷不住了，半小时四题全会了 
/*
好吧只能看CCF 评测机会不会发力了。
nlog^2 n 让我过吧QwQ
我好不容易有一次机会ak的QwQ 
100+100+[70,100]+100=[370,400]
CCF 球球你放我log^2 过了吧QwQ
你可是让NOIP2024T4,5e5都放log^2 过的QwQ
真的求求你了QwQ
哦对了，关注luogu _DEQUE_ 谢谢喵 
*/
