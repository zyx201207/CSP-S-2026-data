#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	string s11 = s1.substr(0,2);
	string s22 = s2.substr(0,2);
	char ss1 = s1[2];
	char ss2 = s2[2];
	int sum1 = ss1-'A'+1;
	int sum2 = ss2-'A'+1;
	if(s11!=s22){
	   cout<<"000";
	   return 0;
	}else{
		cout<<"1";
	}
	if(abs(sum1-sum2)<=2&&sum1<=3&&sum2<=3){
		cout<<"1";
	}else if(abs(sum1-sum2)==1&&sum1>=4&&sum2>=4){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
    }
	if(abs(sum1-sum2) == 1&&((sum1<=3&&sum2<=3)||(sum1>=4&&sum2>=4))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
