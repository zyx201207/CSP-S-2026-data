#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;
string n,m;
void gett(){
	x=0,y=0;
	x+=(n[0]-'0')*10;
	x+=(n[1]-'0');
	y+=(m[0]-'0')*10;
	y+=(m[1]-'0');	
}
int num(){
	return abs((n[2]-'0')-(m[2]-'0'));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt;
	cin>>a>>n>>b>>m;
	gett();
	if(a!=b){
		cnt=4;
	}
	else{
		if(x!=y) cout<<1,cnt=3;
		else{
			if((n[2]>='D'&&m[2]>='D')||(n[2]<='C'&&m[2]<='C'))
				if((num()==1&&(n[2]!='C'||m[2]!='D')&&(n[2]!='D'||m[2]!='C'))||(num()==2&&(n[2]=='D'&&m[2]=='F')||(n[2]=='F'&&m[2]=='D')))
					cout<<1111,cnt=0;
				else cout<<111,cnt=1;
			else
				cout<<11,cnt=2;
		}
	}
	for(int i=1;i<=cnt;i++) cout<<0;
	return 0;
}
