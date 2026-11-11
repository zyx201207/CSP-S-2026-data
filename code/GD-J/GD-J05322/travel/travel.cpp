#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	
	bool flag=true;
	
	if (cr==cx)
		cout<<1;
	else{
		cout<<0;
		flag=false;
	}
	
	string x="",y="";
	x+=sr[0];
	x+=sr[1];
	y+=sx[0];
	y+=sx[1];
	
	if (flag&&x==y){
		cout<<1;
	}else{
		cout<<0;
		flag=false;
	}
	
	if (flag&&((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&(sx[2]=='A'||sx[2]=='C'))||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D')))
		cout<<1<<1;
	else if (flag&&(sr[2]=='A'&&sx[2]=='C'||sr[2]=='C'&&sx[2]=='A'))
		cout<<1<<0;
	else 
		cout<<0<<0;
		
	return 0;
}
