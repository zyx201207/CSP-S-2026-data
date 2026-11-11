//GZ-J00153,遵义市第十九中学,刘婧妍。
#include<bits/stdc++.h>	
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,w=0;
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	int a=1,b=1,c=1,d=1;
	if(n!=m){
		a=0,b=0,c=0,d=0;
	}int x=int(s1[0]-'0')*10+int(s1[1]-'0'),y=int(s2[0]-'0')*10+int(s2[1]-'0');
	char x1=s1[2],y1=s2[2];
	if(x!=y){
		b=0,c=0,d=0;
	}
	if((x1=='D'&&y1=='F')||(x1=='F'&&y1=='D')||(x1=='D'&&y1=='F')||(x1=='F'&&y1=='D')||(x1=='A'&&y1=='B')||(x1=='B'&&y1=='A')||(x1=='B'&&y1=='C')||(x1=='C'&&y1=='B')||(x1=='A'&&y1=='C')||(x1=='C'&&y1=='A')){
		w++;
	}else{
		c=0,d=0;
	}
	if((x1=='D'&&y1=='F')||(x1=='F'&&y1=='D')||(x1=='D'&&y1=='F')||(x1=='F'&&y1=='D')||(x1=='A'&&y1=='B')||(x1=='B'&&y1=='A')||(x1=='B'&&y1=='C')||(x1=='C'&&y1=='B')){
		w++;
	}else{
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
