#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int c1_v,s1_v,s1_b,c2_v,s2_v,s2_b;
int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	cin>>c1>>s1>>c2>>s2;
 	c1_v=(c1[0]-'0')*10+c1[1]-'0';
 	c2_v=(c2[0]-'0')*10+c2[1]-'0';
 	s1_v=(s1[0]-'0')*10+s1[1]-'0';
 	s2_v=(s2[0]-'0')*10+s2[1]-'0';
 	s1_b=s1[2]-'A'+1;
 	s2_b=s2[2]-'A'+1;
 	cout<<(c1_v==c2_v);
 	cout<<(s1_v==s2_v&&c1_v==c2_v);
 	if(((s1_b>=1&&s1_b<=3&&s2_b>=1&&s2_b<=3)||(s1_b>=4&&s1_b<=5&&s2_b>=4&&s2_b<=5))&&(c1_v==c2_v)&&(s1_v==s2_v)){
 		cout<<1;
	}else{
		cout<<0;
	}
	if((abs(s1_b-s2_b)==1&&(!(s1_b==3&&s2_b==4))&&(!(s2_b==3&&s1_b==4)))&&(c1_v==c2_v)&&(s1_v==s2_v)){
		cout<<1;
	}else{
		cout<<0;
	}
 	return 0;
}
