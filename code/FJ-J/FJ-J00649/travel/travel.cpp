#include<bits/stdc++.h>
using namespace std;
string s1,s2,d1,d2;
int ll(char a){
	if(a=='A')return 1;
	if(a=='B')return 2;
	if(a=='C')return 3;
	if(a=='D')return 5;
	if(a=='F')return 6;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s1>>s2>>d1>>d2;
    if(s1==d1){
    	cout<<1;
	}else{
		cout<<0;
	}
	if(s2[0]==d2[0]&&s2[1]==d2[1])cout<<1;
	else cout<<0;
	if((ll(s2[2])<=3&&ll(d2[2])<=3)||(ll(s2[2])>=5&&ll(d2[2])>=5))cout<<1;
	else cout<<0;
	if(abs(ll(s2[2])-ll(d2[2]))==1)cout<<1;
	else cout<<0;
	return 0;
} 
