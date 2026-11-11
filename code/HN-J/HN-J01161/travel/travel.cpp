#include<bits/stdc++.h>
using namespace std;
bool f=1,ff=1;
char c1[10],s1[10],c2[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin.get();
	cin>>s1;
	cin.get();
	cin>>c2;
	cin.get();
	cin>>s2;
	if((c1[1]==c2[1])&&(c1[0]==c2[0])) cout<<"1";
		else{
			cout<<"0";
			ff=0;
		}
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&ff) cout<<"1";
		else{
			cout<<"0";
			f=0;
		} 
	if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&f&&ff) cout<<'1';
		else cout<<"0";
	if(ff&&f&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F'))) cout<<"1";
	 	else cout<<"0";		
	return 0;
}		
