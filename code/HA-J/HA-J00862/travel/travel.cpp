#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,p1,p2;
	char s1,s2;
	cin>>c1>>p1>>s1>>c2>>p2>>s2;
	if(c1==c2){
		if(p1==p2){
			if((s1=='A'&&s2=='B' || s2=='A'&&s1=='B' || s1=='A'&&s2=='C' || s2=='A'&&s1=='C' || s1=='B'&&s2=='C' || s2=='B'&&s1=='C') || (s1=='D'&&s2=='F' || s2=='D'&&s1=='F')){
				if((s1=='A'&&s2=='B' || s2=='A'&&s1=='B' || s1=='B'&&s2=='C' || s2=='B'&&s1=='C') || (s1=='D'&&s2=='F' || s2=='D'&&s1=='F')){ 
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
