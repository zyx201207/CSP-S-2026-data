#include<bits/stdc++.h>
using namespace std;
const int N=0;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){cout<<"0000";return 0;}
	else{
		if((s1[0]!=s2[0])||(s1[1]!=s2[1]))cout<<"1000";
		else{
			bool f1=0,f2=0;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')f1=1;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')f2=1;
			if(f1!=f2)cout<<"1100";
			else{
				if(f1==0&&f2==0)cout<<"1111";
				else{
					if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))cout<<"1110";
					else cout<<"1111";
				}
			}
		}
	}
	return 0;
}
