#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3];
int e[]={0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])
		e[0]=1;
	else
		e[0]=0;
	if(e[0]==1&&b[0]==d[0]&&b[1]==d[1])
		e[1]=1;
	else
		e[1]=0;
	if(e[1]==1&&b[2]=='A'||e[1]==1&&b[2]=='B'||e[1]==1&&b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C')
			e[2]=1;
	}
		
	else{
		if(e[1]==1&&b[2]=='D'||b[2]=='F')
			if(d[2]=='D'||d[2]=='F'){
				e[2]=1;
				e[3]=1;
			}		
		else
			e[2]=0;
	}
	if(e[2]==1){
		if(b[2]=='A'&&d[2]=='B')
			e[3]=1;
		if(b[2]=='B'&&d[2]=='C')
			e[3]=1;
	}
	else
		e[3]=0;
	for(int i=0;i<=3;i++)
		cout<<e[i];
	return 0;
}
