#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else {cout<<0<<0<<0<<0;return 0;}
	if(b[0]+b[1]==d[0]+d[1]){
		cout<<1;
		bool n=0,m=0;
		for(int i='A';i<='C';i++){
			if(b[2]==i) n=1;
			if(d[2]==i) m=1;
		}
		if(n&&m){
			cout<<1;
			if(b[2]-1==d[2]||b[2]+1==d[2]) cout<<1;
			else cout<<0;
			return 0;
		}
		else {cout<<0<<0;return 0;}
		n=m=0;
		for(int i='E';i<='F';i++){
			if(b[2]==i) n=1;
			if(d[2]==i) m=1;
		}
		if(n&&m){
			cout<<1;
			if(b[2]-1==d[2]||b[2]+1==d[2]) cout<<1;
			else cout<<0;
			return 0;
		}
		else {cout<<0<<0;return 0;}
	}
	else{
		cout<<0<<0<<0;
	}
}
