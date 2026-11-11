#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool n[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) n[1]=1;
	if(b[0]==d[0] && b[1]==d[1]&& n[1]==1){
			n[2]=1;
	}
	if(b[2]<='C' && d[2]<='C' && n[2]==1){
			n[3]=1;
	}
	if(b[2]>'C' && d[2]>'C' && n[2]==1){
			n[3]=1;
		}
	if(n[3]==1 && b[2]-d[2]==1){
			n[4]=1;
		}
	if(n[3]==1 && b[2]-d[2]==-1){
			n[4]=1;
		}
		for(int i=1;i<=4;i++){
		cout<<n[i];
		}
	}
