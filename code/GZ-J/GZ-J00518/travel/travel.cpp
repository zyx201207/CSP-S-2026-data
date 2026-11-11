//GZ-J00518 ЌхичЇ≠ 
#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>r1>>r2>>x1>>x2;
	
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}
	
	if(r2[2]=='F')r2[2]='E';
	if(x2[2]=='F')x2[2]='E';
	
	if(r2[0]==x2[0] && r2[1]==x2[1]){
		if((r2[2]+1==x2[2] && x2[2]!='D') || (r2[2]-1==x2[2] && x2[2]!='C'))cout<<"1111";
		
		else if(!((r2[2]=='D' && x2[2]=='C') || (r2[2]=='C' && x2[2]=='D')))cout<<"1110";
		
		else cout<<"1100";	
	}else cout<<"1000";
	
	return 0;
}
