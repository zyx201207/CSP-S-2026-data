#include<bits/stdc++.h>
using namespace std;
int a,a1;
string b,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>a1>>b1;
	if(a==a1){
		cout<<1;
		if(b[0]==b1[0]&&b[1]==b1[1]){
			cout<<1;
			int x=int(b[2]),y=int(b1[2]);
			if((x>=65&&x<=67&&y>=65&&y<=67)||(x>=68&&x<=70&&y>=68&&y<=70)){
				cout<<1;
				if(abs(int(b[2]-b1[2]))==1&&!((b[2]=='C'&&b1[2]=='D'||(b[2]=='D'&&b1[2]=='C'))))cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
