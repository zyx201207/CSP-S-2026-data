#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c=0,d=0,e=0,f=0;
	char a1[10],b1[10];
	cin>>a>>a1>>b>>b1;
	if(a==b){	
		c++;
		if(a1[0]==b1[0]&&a1[1]==b1[1]){	
			d++;
			if(a1[2]==a1[2]&&(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'&&b1[2]=='A'||b1[2]=='B'||b1[2]=='C')||(a1[2]=='E'||a1[2]=='F'&&b1[2]=='E'||b1[2]=='F')){
				e++;
				if(a1[2]+1==b1[2]||a1[2]-1==b1[2])	
					f++;	
		}
			}
				}
	cout<<c<<d<<e<<f;	
	return 0;
}
