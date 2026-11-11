#include<bits/stdc++.h>
using namespace std;
struct z{
	int c;
	string s;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	z r,x;
	cin>>r.c>>r.s>>x.c>>x.s;
	if(r.c==x.c){
		cout<<1;
		if(int(r.s[0])*10+int(r.s[1])==int(x.s[0])*10+int(x.s[1])){
			cout<<1;
			if(((r.s[2]>='A' && r.s[2]<='C')&&(x.s[2]>='A' && x.s[2]<='C'))||((r.s[2]>='D' && r.s[2]<='F')&&(x.s[2]>='D' && x.s[2]<='F'))){
				cout<<1;
				if(abs(r.s[2]-x.s[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
