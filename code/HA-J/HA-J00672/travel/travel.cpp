#include<bits/stdc++.h>
#define endl '\n'
#define debug cout << "qwq" << endl;
using namespace std;

string ra, rb, ca, cb;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//freopen("travel5.in", "r", stdin);
	//关注luogu 554576 谢谢喵。 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> ra >> rb >> ca >> cb;
	if(ra != ca){
		cout << "0000" << endl;
		return 0;
	}else cout << "1";
	
	bool flag = true;
	for(int i = 0; i <= 1; i ++) if(rb[i] != cb[i]) flag = false;
	if(!flag){
		cout << "000" << endl;
		return 0;
	}
	cout << "1";
	if(rb[2] == 'A' ){
		if(cb[2] == 'B') cout << "11";
		else if(cb[2] == 'C') cout << "10";
		else cout << "00";
	}
	if(rb[2] == 'B'){
		if(cb[2] == 'A' || cb[2] == 'C') cout << "11";
		else cout << "00";
	}
	if(rb[2] == 'C'){
		if(cb[2] == 'B') cout << "11";
		else if(cb[2] == 'A') cout << "10";
		else cout << "00";
	}
	if(rb[2] == 'D'){
		if(cb[2] == 'F') cout << "11";
		else cout << "00";
	}
	if(rb[2] == 'F'){
		if(cb[2] == 'D') cout << "11";
		else cout << "00";
	}
	

	return 0;
}
/*
什么叫,CCF网站崩了/jy
什么叫，考试开始十分钟后，有0个选手打开了题面/jy
什么叫，旁边那个人的机子炸了，需要换机器 
*/
