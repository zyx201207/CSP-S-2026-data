#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	string x1,r1;
	cin>>r>>r1>>x>>x1;
	if(r==x){
		if(r1[1]==x1[1]&&r1[0]==x1[0]) {
			if(((r1[2]=='A'||r1[2]=='B'||r1[2]=='C')&&(x1[2]=='A'||x1[2]=='B'||x1[2]=='C'))||((r1[2]=='D'||r1[2]=='F')&&(x1[2]=='D'||x1[2]=='F'))){
				if((r1[2]-1==x1[2]||r1[2]+1==x1[2])||((r1[2]=='F'||r1[2]=='D')&&(x1[2]=='F'||x1[2]=='D'))){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else {
			cout<<"1000";
			return 0;	
		}
	} 
	else {
		cout<<"0000";
		return 0;
	}
	
	
	return 0;
}
