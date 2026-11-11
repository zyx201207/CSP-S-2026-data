#include <bits/stdc++.h>
using namespace std;
bool get(char c){
	return ((c<='C')?1:0);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a == c){
		cout<<1;
		if(b[0] == d[0] && b[1] == d[1]){
			cout<<1;
			if(get(b[2]) == get(d[2])){
				cout<<1;
				if(abs(b[2]-d[2]) == 1)cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";		
	}else cout<<"0000";
	return 0;
}
/*
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%%
%%%sto sto hzk szh tty zjz scx  巨佬们保佑我 J S 不挂分 orz orz%%% 
*/ 
