#include<bits/stdc++.h>
using namespace std;
short int a,b,x,y;
char s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>s>>b>>y>>t;
	if(a!=b) cout<<"0000";
	else{
		cout<<"1";
		if(x!=y) cout<<"000";
		else{
			cout<<"1";
			if((s<='C'&&t<='C')||(s>='D'&&t>='D')){
				cout<<"1";
				if((s=='B'||t=='B')||(s=='D'||t=='D')){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}
	}
	return 0;
}

