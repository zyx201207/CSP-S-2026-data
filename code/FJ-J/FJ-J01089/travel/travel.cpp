#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c;
	cin>>b>>d;
	int x,y;
	char m,n;
	if(a==b){
		cout<<1;
		x=int(c[0]*10+c[1]);
		y=int(d[0]*10+d[1]);
		m=c[2];
		n=d[2];
		if(x==y){
			cout<<1;
			if(((m=='A'||m=='B'||m=='C')&&(n=='A'||n=='B'||n=='C'))||((m=='D'||m=='F')&&(n=='D'||n=='F'))){
				cout<<1;
			}
			else{
				cout<<0;
			}if(((m=='D'||m=='F')&&(n=='D'||n=='F'))||((m=='A'||m=='B')&&(n=='B'||n=='A'))||((m=='B'||m=='C')&&(n=='C'||n=='B'))){
				cout<<1;
			}
			else{
				cout<<0;
			}		
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
}
