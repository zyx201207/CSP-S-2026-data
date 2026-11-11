#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
int n,m,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	for(int i=0;i<2;i++){
		n=n*10+(c[i]-'0');
		m=m*10+(c2[i]-'0');
		x=x*10+(s[i]-'0');
		y=y*10+(s2[i]-'0');
	}
	if(n!=m) cout<<"0000";
	else {
		cout<<"1";
		if(x!=y) cout<<"000";
		else {
			cout<<"1";
			if((s[2]<='C'&&s2[2]>='D')||(s[2]>='D'&&s2[2]<='C')) cout<<"00";
			else {
				cout<<"1";
				int e;
				if(s[2]>s2[2]) e=int(s[2]-s2[2]);
				else e=int(s2[2]-s[2]);
				if(e<=1||(s[2]=='D'&&s2[2]=='F')||(s[2]=='F'&&s2[2]=='D')) cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
