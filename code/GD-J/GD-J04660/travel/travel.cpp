#include<bits/stdc++.h>
using namespace std;
int e[5];
string a,b,c,d;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	e[0]=0;
	e[1]=0;
	e[2]=0;
	e[3]=0;
	if(a==c) {
		e[0]=1;
		if((b[0]==d[0])&&(b[1]==d[1])){
			e[1]=1;
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E'))){
				e[2]=1;
				if((b[2]-d[2]==1)||d[2]-b[2]==1)
					e[3]=1;
			}
		}
			
	}
	for(int i=0;i<=3;i++) cout<<e[i];
	 return 0;
} 
