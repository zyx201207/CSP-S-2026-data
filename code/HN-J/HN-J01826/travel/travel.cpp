#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	int a[4];
    int a1,a2;
    string s1,s2;
    cin >>a1>>s1>>a2>>s2;
    if(a1==a2){
    	a[0]=1;
    	if((s1[0]==s2[0])&&(s1[1]==s2[1])){
    		a[1]=1;
    		if((s1[2]=='A'||s1[2]=='B'||s1[3]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[3]=='C')){
    			a[2]=1;
    			if(s1[2]-s2[2]==0||s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
    				a[3]=1;
				}
			}
			if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='D'||s2[2]=='F')){
    			a[2]=1;
    			a[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++)
		cout<<a[i];
	return 0; 
}
 
