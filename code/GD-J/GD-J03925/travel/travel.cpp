#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;//02 02B 02 01A
	bool flag=true;
	//两张车票对应的座位是否在同一节车厢；
	if(c1==c2&&flag){
		cout<<1;
	}else{
		cout<<0;
		flag=false;
	}
    //两张车票对应的座位是否在同一节车厢的同一排；
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag){
    	cout<<1;
	}else{
		cout<<0;
		flag=false;
		//cout<<endl<<flag;
	}
	bool flag2=false;
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
	//cout<<flag;
	if(flag){
		if(s1[2]>='D'&&s2[2]>='D'){
			cout<<1;
			flag2=true;
		}else if(s1[2]<='C'&&s2[2]<='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	//两张车票对应的座位是否相邻。
	if(flag){
		if(flag2){
			cout<<1;
		}else if(s1[2]=='B'||s2[2]=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
