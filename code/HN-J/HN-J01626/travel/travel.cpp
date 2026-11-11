#include<bits/stdc++.h>
using namespace std;
int r1,x1;
char r2[3],x2[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1;
	for(int i=0;i<3;i++)cin>>r2[i];
	cin>>x1;
	for(int i=0;i<3;i++)cin>>x2[i];
	if(r1==x1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(r2[2]=='D'||r2[2]=='E'){
		if(x2[2]=='D'||x2[2]=='E'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	if(r2[2]=='A'&&x2[2]=='B'){
		cout<<1;
		return 0;
	}
	if(r2[2]=='C'&&x2[2]=='B'){
		cout<<1;
		return 0;
	}	
	if(r2[2]=='B'&&x2[2]=='C'){
		cout<<1;
		return 0;
	}
	if(r2[2]=='B'&&x2[2]=='A'){
		cout<<1;
		return 0;
	}
	if(r2[2]=='D'&&x2[2]=='F'){
		cout<<1;
		return 0;
	}
	if(r2[2]=='F'&&x2[2]=='D'){
		cout<<1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
	
	
	
	
	
	
	
	
	
	
	
}
