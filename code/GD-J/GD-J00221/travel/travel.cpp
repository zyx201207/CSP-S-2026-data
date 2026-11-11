#include<bits/stdc++.h>
using namespace std;
string a,b,u,v,x,y;
char s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>u>>b>>v;
	if(a!=b)cout<<"0000";
	else{
		x=u[0]+u[1];
		y=v[0]+v[1];
		if(x!=y)cout<<"1000";
		else{
			s=u[2];
			t=v[2];
			if(s>t)swap(s,t);
			if(s<='C'&&t>='D')cout<<"1100";
			else{
				if(s=='A'&&t=='B'||s=='B'&&t=='C'||s=='D'&&t=='F')cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
} 
