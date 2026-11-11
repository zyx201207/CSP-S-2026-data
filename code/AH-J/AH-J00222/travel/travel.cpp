#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string x,y,xx,yy;
	cin>>x>>y>>xx>>yy;
	if(y[2]=='F')
		y[2]='E';
	if(yy[2]=='F')
		yy[2]='E';  
	if(x==xx){
		cout<<1;
		if(y[0]==yy[0]&&y[1]==yy[1]){
			cout<<1;
			if((y[2]<='C'&&yy[2]<='C')||(y[2]>='D'&&yy[2]>='D'))
				cout<<1;
			else
				cout<<0;
		}
			
		else 
			cout<<"00";
		bool flag=1;
		if(yy[2]=='C'&&y[2]=='D')
			flag=0;
		if(y[2]=='C'&&yy[2]=='D')
			flag=0;
		string gh=y;
		int a=(y[0]-'0')*10+(y[1]-'0');
		int b=(yy[0]-'0')*10+(yy[1]-'0');
		if(abs(a-b)==1&&y[2]==yy[2])
			cout<<1;
		else if(a==b&&abs(yy[2]-y[2])==1&&flag==1)
			cout<<1;
		else
			cout<<0;
	}
		
	else
		cout<<"0000";
	
	return 0;
} 
