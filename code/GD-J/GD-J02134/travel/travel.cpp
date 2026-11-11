#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char p1,p2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>p1>>c2>>s2>>p2;
	if(c1==c2){	
		if(s1==s2){
			if((p1<'D'&&p2<'D')||(p1>'C'&&p2>'C')){
				if(abs(p1-p2)==1)cout<<1111;
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
