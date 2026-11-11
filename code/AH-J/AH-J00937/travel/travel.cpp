#include<bits/stdc++.h>
using namespace std;
string a,b,r,x;
char r1,x1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>r>>b>>x;
	r1=r[2];
	x1=x[2];
	if(a!=b){
		cout<<"0000";
	}
	else{
		if(r[0]!=x[0] || r[1]!=x[1]){
			cout<<"1000";
		}
		else{
			if(!((r1>='A' && r1<='C' && x1>='A' && x1<='C') || (r1>='D' && r1<='F' && x1>='D' && x1<='F')))
				cout<<"1100";
			else{
				if((r1-1==x1 || r1+1==x1) || ((r1=='D' && x1=='F') || (r1=='F' && x1=='D')))
					cout<<"1111";
				else
					cout<<"1110";
			} 
		}
	}
	return 0;
}
