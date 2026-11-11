#include <bits/stdc++.h>
using namespace std;
string cone, sone, ctwo, stwo;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cone >> ctwo >> sone >> stwo;
	if (cone == sone) {cout << 1;}
	else {cout << "0000"; return 0;}
	if (ctwo[0] == stwo[0]){
	    if (ctwo[1] == stwo[1]){
	        cout << 1;
	    }else{
	    	cout << "000";
	    	return 0;
		}
	}else{
		cout << 0;
	}
	if ((ctwo[2] == 'A' && stwo[2] == 'B') || (ctwo[2] == 'B' && stwo[2] == 'C') || (ctwo[2] == 'A' && stwo[2] == 'C') || (ctwo[2] == 'D' && stwo[2] == 'F') || (ctwo[2] == 'B' && stwo[2] == 'A') || (ctwo[2] == 'C' && stwo[2] == 'B') || (ctwo[2] == 'C' && stwo[2] == 'A') || (ctwo[2] == 'F' && stwo[2] == 'D')){
		cout << 1;
	}else{cout << "00"; return 0;}
	if ((ctwo[2] == 'A' && stwo[2] == 'B') || (ctwo[2] == 'B' && stwo[2] == 'C') || (ctwo[2] == 'D' && stwo[2] == 'F') || (ctwo[2] == 'B' && stwo[2] == 'A') || (ctwo[2] == 'C' && stwo[2] == 'B') || (ctwo[2] == 'F' && stwo[2] == 'D')){
	    cout << 1;
	}else{
        cout << 0;
	}
	return 0;
}
/*
I'm back!
It's time to write a little passage!
But I don't know how to write it~
So my passage might have some water... or be rich of water...
%%%%%%%
So if you can see this passage, please eat it, drink it, hit it, and SAY it!!!!!!!www
希望CCF出的题目能简单一些...
[up][up][up]But I hope this Chinese word can visible...[up][up][up] 
This is a comeptition! I must be duanzhuang!!!!
Duan1 zhuang1 yi4 dian3 ma0!!!!!!
端庄一点嘛！！！！！！！！！！！！！！！！！！！！！！！！！(bushi 
Don't you think putting Chinese and English in a sentense together is really LOL?
Your kaosheng, HN-J00716, at C2502.
Luogu User name: MacaronP_Loves_LUOGU (it's a new user
password: What is it? It's hard to guess~~~~~~ It's :
    Trick||Treat!
6767676767676767676767676767676767676767676767676767676767676767676767
*/
