#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using pii = pair<int,int>;
const int N=2e5+9,M=4e5+9,inf=1e9+9;
const int mode=998244533;

void solved(){
	string cx1,cx2,zw1,zw2;// 车厢 ， 座位
	cin>>cx1>>zw1>>cx2>>zw2;
	
	char st1,st2; //真实座位seat
	st1=zw1[2],st2=zw2[2];
	
	string p1,p2;//真实排 p 
	p1=zw1[0]+zw1[1],p2=zw2[0]+zw2[1];
	
	if(cx1==cx2){//直接使用字符串判等即可 
		if(p1==p2){//同车厢同排 
			if((st1=='F'||st1=='D')&&(st2=='F'||st2=='D')){//当为上侧的 
				cout<<"1111";//同排相邻 
			}else if((st1=='A'||st1=='B'||st1=='C')&&(st2=='A'||st2=='B'||st2=='C')){
					if(abs((int)st1-(int)st2)<=1)cout<<"1111";//同排相邻 
					else cout<<"1110";//同排隔了一个 
			}
			else cout<<"1100";//同排不同侧 
		}else cout<<"1000";//同车不同排 
	}else cout<<"0000";//不同车厢 
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solved(); 
	return 0;
}
/*
思路：
从大往小判断，第一个不行后面就都不行 
本质模拟题，没什么好说的
时间 O 1 , 空间 O 1
ok!
我觉得这个可以写个对拍自己看看是否正确
 
*/
