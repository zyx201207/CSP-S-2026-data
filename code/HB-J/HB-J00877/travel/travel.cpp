#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}cout<<"1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}cout<<"1";
	int k1=s1[2],k2=s2[2]; int ak=max(k1,k2),ik=min(k1,k2);
	if((ik=='A'&&ak=='B')||(ik=='B'&&ak=='C')||(ik=='A'&&ak=='C')||(ik=='D'&&ak=='F')){
		if(ik=='A'&&ak=='C') cout<<"10";
		else cout<<"11";
		return 0;
	}
	cout<<"00";
	return 0;
}
