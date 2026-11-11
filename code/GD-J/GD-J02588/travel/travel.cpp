#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int v[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1;
	cin>>s2>>c2;
	if(s1[0]==s2[0] && s1[1]==s2[1]) v[1]=1;
	else{
		v[1]=0;
	} 
	if(c1[0]==c2[0] && c1[1]==c2[1] && v[1]==1){
		v[2]=1;
	} 
	else{
		v[2]=0;
	} 
	if(c2[2]=='F' && 'D'==c1[2] && v[2]==1) 	v[3]=1;
	else if(c1[2]=='F' && 'D'==c2[2] && v[2]==1)	v[3]=1;
	else if('A'==c2[2] && c1[2]=='B' && v[2]==1) v[3]=1;
	else if(c2[2]=='B' && 'A'==c1[2] && v[2]==1) v[3]=1;
	else if('B'==c2[2]  && 'C'==c1[2] && v[2]==1) v[3]=1;
	else if(c2[2]=='C' && c1[2]=='B' && v[2]==1) v[3]=1;
	else if(c2[2]=='C' && c1[2]=='A' && v[2]==1) v[3]=1;
	else if(c2[2]=='A' && c1[2]=='C' && v[2]==1) v[3]=1;
	else v[3]=0;
	if(c2[2]=='F' && 'D'==c1[2] && v[2]==1) 	v[4]=1;
	else if(c1[2]=='F' && 'D'==c2[2] && v[2]==1) v[4]=1;
	else if('A'==c2[2] && c1[2]=='B' && v[2]==1) v[4]=1;
	else if(c2[2]=='B' && 'A'==c1[2] && v[2]==1) v[4]=1;
	else if('B'==c2[2]  && 'C'==c1[2] && v[2]==1) v[4]=1;
	else if(c2[2]=='C' && c1[2]=='B' && v[2]==1) v[4]=1;
	else v[4]=0;
	for(int i=1;i<=4;i++){
		cout<<v[i];
	}
	return 0;
}
