#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2,t1,t2;
char a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a1>>c2>>s2>>a2;
	if(a1=='F' or a1=='D') t1=1;
	else t1=2;
	if(a2=='F' or a2=='D') t2=1;
	else t2=2;
	if(c1==c2) cout<<"1";
	else if(c1!=c2){
			cout<<"0000";
			return 0;
		}	
	if(s1==s2) cout<<"1";
	else if(s1!=s2){
			cout<<"000";
			return 0;
		}
	if(t1==t2) cout<<"1";
	else if(t1!=t2){
			cout<<"00";
			return 0;
		}
	if(t1==1) cout<<"1";
	if(a1=='B' or a2=='B') cout<<"1";
	else if(a1!=a2){
			cout<<"1110";
			return 0;
		}
	return 0;
}
