#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	 freopen("travel.out","w",stdout);
	
	 string c1,s1,c2,s2,j="0000";
	 cin>>c1>>s1>>c2>>s2;
	 j[0]=j[1]=j[2]=j[3]='0';
	 if(c1==c2){
		 j[0]='1';
		 if(s1[0]==s2[0]&&s1[1]==s2[1]){
			 j[1]='1';
			 if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				 j[2]='1';
				 if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					 j[3]='1';
					 cout<<j;
				 }
				 else{
					 cout<<j;
				 }
			 }else
			 {
				 cout<<j;
			 }
		 }
		 else{
			 cout<<j;
		 }
	 }
	 else{
		 cout<<j;
	 }
	
	
	return 0;
}

