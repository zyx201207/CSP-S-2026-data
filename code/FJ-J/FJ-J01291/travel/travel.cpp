#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	cout<<1;
	int a1 = (s1[0]-'0')*10+(s1[1]-'0');
	int a2 = (s2[0]-'0')*10+(s2[1]-'0');
	if(a1==a2){
		cout<<1;
		int p =s1[2]-'A';
		int q =s2[2]-'A';
		if((p<3&&q<3)||(p>=3&&q>=3)){
			cout<<1;
			if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)cout<<1;
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
	
	}
	else cout<<"0000";
	return 0;
}
