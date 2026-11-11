#include<bits/stdc++.h>//100
using namespace std;
string c1,s1,c2,s2;//分别为小 R 的车票上的车厢号、座位号，以及小 X 的车票上的车厢号、座位号 
char sr,sx;
bool ans_1,ans_2,ans_3,ans_4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	sr=s1[2],sx=s2[2];
	if((c1[0]-'0')*10+c1[1]-'0'==(c2[0]-'0')*10+c2[1]-'0'){
		ans_1=true;
	}else{
		ans_1=false;
	}
	if((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0'){
		if(ans_1)ans_2=true;
		else ans_2=false;
	}else{
		ans_2=false;
	}
	if((sr>='A'&&sr<='C'&& (sx=='D'||sx=='F') )||(sx>='A'&&sx<='C'&& (sr=='D'||sr=='F') )){
		ans_3=false;
	}else{
		if(ans_2)ans_3=true;
		else ans_3=false;
	}
	if(ans_3==false){
		ans_4=false;
	}else{
		if(abs(sr-sx)==1)ans_4=true;
		else ans_4=false;
	}
	cout<<ans_1<<ans_2<<ans_3<<ans_4;
	return 0;
}
