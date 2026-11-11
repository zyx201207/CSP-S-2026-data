#include<bits/stdc++.h>
using namespace std;
long long c1,c2,add1,add2,sum1,sum2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		add1+=(s1[0]-'0')*10+(s1[1]-'0');
		add2+=(s2[0]-'0')*10+(s2[1]-'0');
		if(add1==add2){
			cout<<"1";
			sum1=s1[2]-'A'+1;
			sum2=s2[2]-'A'+1;
			if((sum1<=3&&sum2<=3)||(sum1>=4&&sum2>=4)){
				cout<<"1";
				if((sum1==1&&sum2==2)||(sum2==1&&sum1==2)||(sum1==2&&sum2==3)||(sum1==3&&sum2==2)||(sum1==4&&sum2==6)||(sum1==6&&sum2==4)){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

