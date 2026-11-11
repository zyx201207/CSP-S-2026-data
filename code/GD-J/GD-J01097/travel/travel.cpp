#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]+s1[1]==s2[0]+s2[1])cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]+s1[1]==s2[0]+s2[1]){
		bool a1,a2;
		a1=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
		a2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
		if(a1==a2){
			cout<<1;
			if(a1==0)cout<<1;
			else{
				if(abs(int(s1[2]-s2[2]))==1)cout<<1;
				else cout<<0;
			}
		}
		else cout<<"00";
	}
	else cout<<"00";
	return 0;
} 
