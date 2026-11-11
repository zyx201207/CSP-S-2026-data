#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		puts("0000");
		return 0;
	}
	cout<<1;	
	int p1=(s1[0]-'0')*10+s1[1],p2=(s2[0]-'0')*10+s2[1];
	if(p1!=p2){
		puts("000");
		return 0;
	}
	cout<<1;
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		cout<<1;
		if(abs(s1[2]-s2[2])==1){
			puts("1");
			return 0;
		}
		else{
			puts("0");
			return 0;
		}
	}
	else{
		puts("00");
		return 0;
	}	
	return 0;
}
