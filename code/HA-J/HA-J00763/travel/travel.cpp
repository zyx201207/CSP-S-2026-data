#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int a=(s1[0]-'0')*10+s1[1]-'0',b=(s2[0]-'0')*10+s2[1]-'0';
		int m=s1[2],n=s2[2];
		if(a==b){
			cout<<"1";
			if((m<=int('C')&&n<=int('C'))||(m>=int('D')&&n>=int('D'))){
				cout<<"1";
				if(abs(m-n)==1)cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
