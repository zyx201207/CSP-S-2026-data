/*
	Luogu id: 
	
		werfvcxs     TabCapsLockShiftzxswq     hn ,kj     gb mjh
	
	Wei Qi Lai De Si Ge Zi Mu Jiu Shi id
	£¨shi zai cai bu chu lai jiu qu wen "abc1223" || "yang_youcheng"£© 
*/

// uid wo ye ji bu zhu
// kan dao zhe fen zhu shi de RP++
// cai cai id ba QwQ

// yuan ben yao xie wang zhe id de
// you te shu zi fu da bu chu lai...

/*

	chuang wai de tian qi
	jiu xiang shi
	ni duo bian de biao qing~
	xia yu le
	yu pei wo ku qi~
	kan bu qing
	wo ye bu xiang kan qing
	
	li kai ni wo an jing de chou li
	bu ren jie xiao de ju qing
	wo de lei liu zai xin li
	xue~ hui~ fang~ qi~
	
	ting yu de sheng yin
	yi di di qing xi
	ni de hu xi xiang yu di shen ru wo de ai li
	zhen xi wang yu neng xia bu ting
	rang xiang nian ji xu 
	rang ai bian tou ming
	wo ai shang gei wo yong qi de raine love
	
	chuang wai de yu di
	yi di di lei ji
	wu nei de shi qi xiang chu cun ai ni de ji yi
	zhen xi wang yu neng xia bu ting
	yu ai de mi mi
	neng yi zhi yan xu
	wo xiang xin wo jiang hui kan dao cai hong de mei li~~~~~~~~~~~~~~~~~~
	
	ZHE QI SHEN LE
	
*/

/*
	wo yao wan wang zhe!!!!!!!!!!!!!
*/

/*
	hao xiang shi yao AFO le
	duo xie dian ba
*/

/*
	wo zai xue xiao de hou zhuo jiu zuo zai wo pang bian!	
*/

/*
	love zxy......
*/

#include<bits/stdc++.h>
using namespace std;

int c1, c2;
int p1, p2;
char z1, z2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> p1 >> z1;
	cin >> c2 >> p2 >> z2;
	if (c1 == c2) {
		cout << 1;
		if (p1 == p2) {
			cout << 1;
			if ((z1 == 'C' && z2 == 'D') || (z1 == 'D' && z2 == 'C')) 
				cout << "00";
			else {
				cout << 1;
				if (abs(z1-z2) == 1) 
					cout << 1;
				else
					cout << 0;
			}
		}
		else 
			cout << "000";
	}
	else 
		cout << "0000";
	return 0;
} 
