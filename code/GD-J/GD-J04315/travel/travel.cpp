#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	else{
		cout<<"1";
		int x,y;
		x=(b[0]-'0')*10+b[1]-'0';
		y=(d[0]-'0')*10+d[1]-'0';
		if(x!=y){
			cout<<"000";
		}
		else{
			cout<<"1";
			int x,y;
			x=max(b[2]-'A'+1,d[2]-'A'+1);
			y=min(b[2]-'A'+1,d[2]-'A'+1);
			if(x==6&&y==4)cout<<"11";
			else if((x==3&&y==2)||(x==2&&y==1))cout<<"11";
			else if(x==3&&y==1)cout<<"10";
			else cout<<"00"; 
		}
	}
} 
