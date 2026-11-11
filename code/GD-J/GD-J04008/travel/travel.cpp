#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int r,x;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		char ch=s1[i];
		if(ch>='0' && ch<='9') r=r*10+(ch-'0');
		else r=r*10+(ch-64);
	}
	for(int i=0;i<s2.size();i++){
		char ch=s2[i];
		if(ch>='0' && ch<='9') x=x*10+(ch-'0');
		else x=x*10+(ch-64);
	}
	if(r/10==x/10) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	r%=10;x%=10;
	if((r>=1 && r<=3 && x>=1 && x<=3) || (r>=4 && r<=5 && x>=4 && x<=5)) cout<<1;
	else{
		cout<<"00";return 0;
	}
	if(max(r,x)-min(r,x)==1) cout<<1;
	else cout<<0;
	return 0;
}
