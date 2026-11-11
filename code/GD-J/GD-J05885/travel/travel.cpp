#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
//8:33 CCF原来你知道今天是万圣节，好幽默的解压密码hhh
//8:36 这第一题有点过分简单了哈哈，最难的部分是取一个漂亮的变量名
//8:37 既然是小R和小X，那就叫cr和cx吧嗯嗯 
//8:39 哇，这个数据好小 
//8:44 看我三目运算符 
//8:47 写一个大if更好 
//8:53 ok写完了第一题,会不会有点慢了aaa 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			if(sr[2]<'D'&&sx[2]<'D'){
				if(abs(sr[2]-sx[2])==1) cout<<"1111";
				else cout<<"1110";
			}
			else if(sr[2]>='D'&&sx[2]>='D') cout<<"1111";
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
} 
