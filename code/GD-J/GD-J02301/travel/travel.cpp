#include <bits/stdc++.h>
using namespace std;

int main(){
	/*
	fang bao 0
	1. qu xiao freopen zhu shi;
	2. bao cun wen jian;
	3. shan diao qi ta wen jian;
	10:55 ´òÁåÁË 
	*/
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car1,car2,seat1,seat2;
	cin>>car1>>seat1>>car2>>seat2;
	int carA,carB,seatA,seatB;
	carA=(car1[0]-'0')*10+(car1[1]-'0');
	carB=(car2[0]-'0')*10+(car2[1]-'0');
	if(carA==carB)cout<<1;
	else cout<<0;
	seatA=(seat1[0]-'0')*100+(seat1[1]-'0')*10+(seat1[2]-'A');
	seatB=(seat2[0]-'0')*100+(seat2[1]-'0')*10+(seat2[2]-'A');
	int minn=min(seatA,seatB);
	int maxn=max(seatA,seatB);
	if(carA==carB&&minn/10==maxn/10)cout<<1;
	else cout<<0;
	if((carA==carB)&&(minn/10==maxn/10)&&((minn%10==3&&maxn%10==5)||(minn%10==1&&maxn%10==2)||(minn%10==0&&maxn%10==1)||(minn%10==0&&maxn%10==2)))cout<<1;
	else cout<<0;
	if((carA==carB)&&(minn/10==maxn/10)&&((minn%10==3&&maxn%10==5)||(minn%10==1&&maxn%10==2)||(minn%10==0&&maxn%10==1)))cout<<1;
	else cout<<0;
}
/*
Luogu id:2027095(NAME:ChenTingXuan)
I MUST GO ON THE MOST UNREASINABLE CODE(MI HUO DAI MA DA SHANG)!!!!
This is my first time to attend the CSP-J second round!
~100pts

I LOVE CCF(not)  IT'S TOO DIFFICULT!
IT'S NOT PREPARE FOR HUMAN! 
*/
