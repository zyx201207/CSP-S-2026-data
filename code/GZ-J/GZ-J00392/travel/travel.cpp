//GZ-J00392 兴义市弘毅中学  刘筱雨
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	int count[3]={0};
    if(c1==c2){
    	count[0]=1;
    	for(int i=0;i<4;i++){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		count[1]=1;
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			count[2]=1;
		    if((s2[2]=='A'&&s1[2]=='C')||(s1[2]=='A'&&s2[2]=='C')) count[3]==0;
		    else count[3]=1;
			}  
			}
		if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]=='D'||s2[2]=='F'){
				count[2]=1;
				count[3]=1;
			}
		                                      }
    }
	}
	}	
	for(int i=0;i<4;i++) cout<<count[i];
	return 0;
}
