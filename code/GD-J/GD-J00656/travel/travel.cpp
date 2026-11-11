#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		a=int(s1[0]-'0')*10+int(s1[1]-'0');
		b=int(s2[0]-'0')*10+int(s2[1]-'0');
		if(a!=b) cout<<"1000";
		else{
			c=s1[2]-'A'+1;
			d=s2[2]-'A'+1;
			if(c<=3&&d<=3||c>3&&d>3){
				if(c==6) c=5;
				if(d==6) d=5;
				if(abs(c-d)==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
	return 0;
}
