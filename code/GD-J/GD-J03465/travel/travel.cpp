#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
bool ans[4];
bool ce[6]={1,1,1,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		ans[0]=1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			ans[1]=1;
			if(ce[sr[2]-'A']==ce[sx[2]-'A']){
				ans[2]=1;
				if((ce[sr[2]-'A'])==1){
					if(sr[2]=='A'&&sx[2]=='B'){
						ans[3]=1;
					}else if(sr[2]=='B'&&sx[2]=='A'){
						ans[3]=1;
					}else if(sr[2]=='B'&&sx[2]=='C'){
						ans[3]=1;
					}else if(sr[2]=='C'&&sx[2]=='B'){
						ans[3]=1;
					}
				}else{
					if(sr[2]=='D'&&sx[2]=='F'){
						ans[3]=1;
					}else if(sr[2]=='F'&&sx[2]=='D'){
						ans[3]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++)cout<<ans[i];
	
	return 0;
} 
