#include<bits/stdc++.h> 
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	char p1=s1[0]+s1[1],p2=s2[0]+s2[1];
	if(p1==p2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char q1=s1[2],q2=s2[2];
	if(q1<q2){
		char o=q1;
		q1=q2;
		q2=o;
	}
	if(q1!='D')cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(q1-1==q2)cout<<"1";
	else cout<<"0";
	return 0;
}
