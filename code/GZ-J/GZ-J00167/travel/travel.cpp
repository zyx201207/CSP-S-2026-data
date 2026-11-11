//GZ-J00167 贵阳市第一中学 谢云龙 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int p1,p2,x1,x2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-48)*10+s1[1]-48;
	x1=s1[2]-'A'+1;
	p2=(s2[0]-48)*10+s2[1]-48;
	x2=s2[2]-'A'+1;
	//1
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	//2
	if(p1==p2)cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	//3
	if((x1<=3&&x2<=3)||(x1>3&&x2>3)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	//4
	if((x1<=3&&x2<=3&&abs(x1-x2)==1)||(x1>3&&x2>3)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
