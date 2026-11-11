#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
char s[4]={'0','0','0','0'};
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		s[0]='1';
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1]&&s[0]=='1'){
		s[1]='1';
	}
	char x=r2[2],y=x2[2];
	if(((x<='C'&&y<='C')||(x>='D'&&y>='D'))&&s[1]=='1'){
		s[2]='1';
	}
	int xx=(int)x,yy=(int)y;
	if((x+1==y||y+1==x||(x==68&&y==70)||(y==68&&x==70))&&s[2]=='1'&&s[1]=='1'){
		s[3]='1';
	}
	cout<<s;
	return 0;
} 
