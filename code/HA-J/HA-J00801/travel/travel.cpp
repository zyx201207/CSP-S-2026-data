#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){  //同节车厢 
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int ns1=(s1[0]-'0')*10+(s1[1]-'0');
	int ns2=(s2[0]-'0')*10+(s2[1]-'0');
	if (ns1==ns2){  //同一排 
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	
	if ((s1[2]<='C')==(s2[2]<='C')){  //过道一侧 
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	int c=abs(s1[2]-s2[2]);
	if (c==1){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
