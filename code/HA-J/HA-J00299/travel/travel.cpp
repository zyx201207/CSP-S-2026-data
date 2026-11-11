#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,b1,b2,b3;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>a1>>s1>>b1>>s2;
	a2=(s1[0]-'0')*10+s1[1]-'0';
	a3=s1[2]-'A';if(a3==3)a3=4;
	b2=(s2[0]-'0')*10+s2[1]-'0';
	b3=s2[2]-'A';if(b3==3)b3=4;
	if(a1==b1){
		if(a2==b2){
			if((a3<3&&b3<3)||(a3>3&&b3>3)){
				if(abs(a3-b3)==1)cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	
	return 0;
}