#include<bits/stdc++.h>
using namespace std;
string r1,x1,r2,x2;
int miku(char a){
	switch(a){
		case 'A':
		case 'B':
		case 'C':
			return 1;
		case 'D':
		case 'F':
			return 2;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		if(r2[0]==x2[0]&&x2[1]==r2[1]){
			if(miku(r2[2])==miku(x2[2])){
				if(miku(r2[2])==2||abs(r2[2]-x2[2])==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
