#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int i,j,s=0;
	string c1,c2,s1,s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if((s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')){
			cout<<"11";
			}
			else{
				if(s1[2]=='A'&&s2[2]=='B'){
				cout<<11;
				s=1;
				}
				if(s1[2]=='B'&&s2[2]=='A'){
				s=1;
				cout<<11;
				}
				if(s1[2]=='A'&&s2[2]=='C'){
				cout<<10;s=1;
				}
				if(s1[2]=='C'&&s2[2]=='A'){
				s=1;cout<<10;
				}
				if(s1[2]=='C'&&s2[2]=='B'){
				s=1;cout<<11;
				}
				if(s1[2]=='B'&&s2[2]=='C'){s=1;
				cout<<11;
				}
				if(s==0)
				cout<<"00";
			}
		}
		else
		cout<<"000";
	}
	else
	cout<<"0000";	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
