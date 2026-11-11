#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[5]={0,0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a[1]=1;
	if(a[1]==1 and s1[0]==s2[0] and s1[1]==s2[1]) a[2]=1;
	if(a[2]==1){
		if((s1[2]=='F' and s2[2]=='D') or (s2[2]=='F' and s1[2]=='D')){
			a[3]=1;	
			a[4]=1;
		} 
		if(s1[2]=='A'){
			if(s2[2]=='B'){
				a[3]=1;	
				a[4]=1;
			}
			if(s2[2]=='C'){
				a[3]=1;	
			}
		}
		else if(s1[2]=='B'){
			if(s2[2]=='A'){
				a[3]=1;	
				a[4]=1;
			}
			if(s2[2]=='C'){
				a[3]=1;
				a[4]=1;	
			}
		}
		else if(s1[2]=='C'){
			if(s2[2]=='B'){
				a[3]=1;	
				a[4]=1;
			}
			if(s2[2]=='A'){
				a[3]=1;	
			}
		}
	}	
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
} 
