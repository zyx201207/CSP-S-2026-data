#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//车厢 
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	//排 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	//过道
	int a=s1[2]+1-'A',b=s2[2]+1-'A';
	if(a<=3&&b<=3){
		cout<<1;
	}else if(a>3&&b>3){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	//相邻
	if(abs(a-b)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
