#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int a=0,b=0,c=0,d=0;
	if(x1==x2){
		a=1;
		if(y1[0]==y2[0]&&y1[1]==y2[1]){
			b=1;
			if('A'<=y1[2]&&y1[2]<='C'&&'A'<=y2[2]&&y2[2]<='C'){
				c=1;	
				if(y1[2]=='A'&&y2[2]=='B'||y1[2]=='B'&&y2[2]=='C'){
					d=1;
				}
			}
			else if('D'<=y1[2]&&y1[2]<='F'&&'D'<=y2[2]&&y2[2]<='F'){
				c=1;
				d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}