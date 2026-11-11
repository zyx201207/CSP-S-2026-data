#include<bits/stdc++.h>
using namespace std;
long long c1,c2,R,X,rl,xl;
string s1,s2,ss=" ABCDF",res="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	// 两张车票对应的座位是否在同一节车厢
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	//两张车票对应的座位是否在同一节车厢的同一排
	R=(s1[0]-'0')*10+(s1[1]-'0');
	X=(s2[0]-'0')*10+(s2[1]-'0');
	//cout<<"=="<<R<<" "<<X<<"==";
	if(R==X){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	for(int i=1;i<=6;i++){
		if(s1[2]==ss[i]) rl=i;
		if(s2[2]==ss[i]) xl=i;
	}
	if(rl<=3&&xl<=3 || rl>3&&xl>3){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	//两张车票对应的座位是否相邻
	if(abs(rl-xl)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
