#include<bits/stdc++.h>
using namespace std;
int c1,c2,jg[4]={0};
char s1[3],s2[3];
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		jg[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    jg[1]=1;
		    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		    	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		    		jg[2]=1;
		    		if(s1[2]-1==s2[2]||s2[2]-1==s1[2]){
		    			jg[3]=1;
					}
				}
			}
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					jg[2]=1;
					if(s1[2]-1==s2[2]||s2[2]-1==s1[2]){
		    			jg[3]=1;
					}
				}
			}
	    }
    }
	for(int i=0;i<=3;i++){
		printf("%d",jg[i]);
	}
	return 0;
}
