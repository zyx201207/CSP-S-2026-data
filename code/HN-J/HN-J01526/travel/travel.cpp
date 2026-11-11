#include<bits/stdc++.h>
using namespace std;
bool tc(char x,char y){
	if(x=='A' || x=='B' || x=='C'){
		if(y=='A' || y=='B' || y=='C'){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(y=='D' || y=='E'){
			return 1;
		}else{
			return 0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		string t1,t2;
		char c1=b[0],c2=d[0];
		t1+=c1;
		t2+=c2;
		t1+=b[1];
		t2+=d[1];
		if(t1==t2){
			cout<<1;
			if(tc(b[2],d[2])){
				cout<<1;
				int x=b[2]-'A',y=d[2]-'A';
				if(abs(x-y)==1){
					cout<<1; 
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	} else{
		cout<<"0000";
	}
	return 0;
}
/*
luogu name:yiwugougou
can you 关注 me?
去年上了迷惑行为大赏，说要保分符，这里保分符批发，要的用CSP-S中的一分给我换。 

AAA保分符批发 
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
   _____ 
  |    |
  | 保 |
  | 分 |
  | 符 |
 _|    |_
|        |
|保佑代码|
|  无bug |
|_      _|
  |    |
  | 保 |
  | 分 |
  | 符 |
  |____|
*/ 
