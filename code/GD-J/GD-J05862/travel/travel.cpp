#include <bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		//
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"000";
		else{
			cout<<"1";
			//
			char op='A',n=s1[2],m=s2[2];
			bool opn,opm,bol;//ÄÇÒ»²â1==left 0=right
			for(int i=0;i<=4;i++){
				if(op+i<='C') bol=1;
				else bol=0;
				if(op+i==n) opn=bol;
				if(op+i==m) opm=bol;
			}
			if(opn!=opm) cout<<"00";
			else{
				cout<<"1";
				//
				if(n==m-1||n==m+1) cout<<"1";
				else cout<<"0";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
