#include <bits/stdc++.h>
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
		cout<<1;
		string p1=s1.substr(0,2),p2=s2.substr(0,2);
		char zw1=s1[2],zw2=s2[2];
		if(p1==p2){
			if(((zw1=='A'||zw1=='B'||zw1=='C')&&(zw2=='E'||zw2=='D'))||((zw2=='A'||zw2=='B'||zw2=='C')&&(zw1=='E'||zw1=='D'))){
				cout<<"100";
			}else{
				if(zw1+1==zw2||zw2+1==zw1)cout<<"111";
				else cout<<"110";
			}
		}
		else cout<<"000";
	}
	return 0;
}
