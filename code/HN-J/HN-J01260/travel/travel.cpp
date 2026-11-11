#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[5],s2[5];
int res[4+2];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2) {
		res[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			res[2]=1;
		if(s1[2]>'C'&&s2[2]>'C') {
			res[3]=1;
			if(int(s1[2])-1==int(s2[2])||int(s1[2])+1==int(s2[2]))
				res[4]=1;
		}
		if(s1[2]<='C'&&s2[2]<='C') {
			res[3]=1;
			if(int(s1[2])-1==int(s2[2])||int(s1[2])+1==int(s2[2]))
				res[4]=1;
		}
		}
	}
	for(int i=1; i<=4; i++)
		cout<<res[i];
	return 0;
}
