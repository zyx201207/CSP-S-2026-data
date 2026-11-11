#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p1,p2;
string ans;
int w1,w2;
bool f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) ans="0000";
	else{
		ans+='1';
		p1=s1[0]+s1[1];
		p2=s2[0]+s2[1];
		if(p1!=p2) ans+="000";
		else{
			ans+='1';
			w1=s1[2]-'A'+1;
			w2=s2[2]-'A'+1;
			if(w1>=1&&w1<=3) f1=1;
			if(w2>=1&&w2<=3) f2=1;
			if(f1!=f2) ans+="00";
			else{
				ans+='1';
				if(abs(w1-w2)==1) ans+='1';
				else ans+='0';
			}
		}
	}
	cout<<ans;
	return 0;
} 
