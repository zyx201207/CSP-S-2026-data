#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char q1,q2;
	cin>>c1>>s1>>q1>>c2>>s2>>q2;
	cout<<(c1==c2);
	cout<<((s1==s2)&&(c1==c2));
	if(max(q1,q2)<='C'&&(c1==c2)&&(s1==s2)){
		cout<<"1";
		if(abs(int(q1-q2))==1){
			cout<<'1';
		}else{
			cout<<"0";
		}
	}else if(min(q1,q2)>'C'&&(c1==c2)&&(s1==s2)){
		cout<<"11";
	}else{
		cout<<"00";
	}
	
}
