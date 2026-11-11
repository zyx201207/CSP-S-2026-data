#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			char p1=s1[2],p2=s2[2];
			int sd1,sd2;
			if(p1=='A' || p1=='B'|| p1=='C') sd1=0;
			else sd1=1;
			if(p2=='A' || p2=='B'|| p2=='C') sd2=0;
			else sd2=1;
			if(sd1==sd2){
				cout<<1;
				if(abs(p2-p1)==1 || (p1=='D' && p2=='F')|| (p2=='D' && p1=='F') ){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		} 
		else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	
	
	return 0;
	
	
} 
