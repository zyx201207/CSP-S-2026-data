#include <bits/stdc++.h> 
using namespace std;
string ax,ay,bx,by;
bool f[5]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>ay>>bx>>by;
	if (ax==bx){
		f[1]=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if (ay[0]==by[0]&&ay[1]==by[1]){
		f[2]=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	int a=ay[2]-'A'+1;
	int b=by[2]-'A'+1;
	if ((0<=a&&a<=3&&0<=b&&b<=3)||(4<=a&&a<=5&&4<=b&&b<=5)){
		f[3]=1;
	}else{
		cout<<"1100";
		return 0;
	}
	if ((a-1==b&&a!=4)||(a+1==b&&a!=3)){
		f[4]=1;
	}else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
	
	
}
