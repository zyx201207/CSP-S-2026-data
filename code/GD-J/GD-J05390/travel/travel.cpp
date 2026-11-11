#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2,ans="0000";
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//  freopen
//  xmh&x?? bro&sis 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			char a=s1[2],b=s2[2];
			if((a+1==b||b+1==a||(a=='A'&&b=='C')||(a=='C'&&b=='A'))&&(!((a=='C'&&b=='D')||(a=='D'&&b=='C')))){
				ans[2]='1';
				if(a+1==b||b+1==a) ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}
