#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
long long sc[4]={0,0,0,0};
void dfs(){
	long long i;
	for(i=0;i<4;i++){
			cout<<sc[i];
		}
}
int main(){
		
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	long long w,z,y,x,a,b,c,d,e,f,g,h,j,i,k,l,m,n,o,p,q,r,s,t,u,v;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		dfs();
		return 0;
		
	}
 
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s2[2]%s1[2]==1){
			if((s2[2]=='C'&&s1[2]=='D')||(s2[2]=='D'&&s1[2]=='C')){
				sc[1]=1;
				sc[0]=1;
				dfs();	
				return 0;
			}else{
				for(j=0;j<4;j++){
					sc[i]=1;
					cout<<sc[i];
				}
			}	
		}else if(s2[2]%s1[2]!=1){
			sc[0]=1;
			sc[1]=1;
			sc[2]=1;
			dfs();
		}
	}else{
		sc[0]=1;
		dfs();
	}
	return 0;
}
