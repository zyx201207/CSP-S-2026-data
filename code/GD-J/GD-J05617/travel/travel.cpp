#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int a=0,b=0;
	for(int i=0;i<=1;i++){
		a+=s1[i];
		b+=s2[i];
	}
	if(a==b) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int c[5]={0};
	a=s1[2]-64;
	b=s2[2]-64;
	if(a==3||a==4&&b==3||b==4){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
		if(a-b==1) cout<<"1";
		else{
			if(b-a==1) cout<<"1";
			else cout<<"0";
		} 
	}
	return 0;
}
