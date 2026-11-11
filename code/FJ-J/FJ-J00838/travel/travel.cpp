#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	string p1,p2;
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	
	char x=s1[2],y=s2[2];
	
	if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(x=='A'||x=='B'||x=='C'){
				if(y=='A'||y=='B'||y=='C'){
					cout<<1;
					if((x=='A'&&y=='C')||(x=='C'&&y=='A')) cout<<0;
					else cout<<1;
				}
				else cout<<"00";
			}
			if(x=='D'||x=='F'){
				if(y=='D'||y=='F'){
					cout<<"11";
				}
				else cout<<"00";
			}
			
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
