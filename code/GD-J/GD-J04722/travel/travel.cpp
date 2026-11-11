#include <bits/stdc++.h>
using namespace std;
bool cx,r,gd,xl;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2,srow,crow;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cx=1;
		srow=s2.substr(0,2);
		crow=c2.substr(0,2);
		if(srow==crow){
			r=1;
			if((s2[2]<='C'&&c2[2]<='C')||(s2[2]>='D'&&c2[2]>='D')){
				gd=1;
				if(abs(s2[2]-c2[2])==1) xl=1;
			}
		}
	}
	cout<<cx<<r<<gd<<xl;
	return 0;
} 
