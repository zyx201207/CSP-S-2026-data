#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	scanf("%d",&c1);
	scanf("%d",&s1);
	scanf("%d",&c2);
	scanf("%d",&s2);
	if(c1!=c2){
		printf("%d%d%d%d",0,0,0,0);
	}else if(s1[0]!=s2[0]&&s1[1]!=s2[1]){
		printf("%d%d%d%d",1,0,0,0);
	}	 else if(s1[2]<='C'&&s2[2]>='D'||s1[2]>='D'&&s2[2]<='C'){
		printf("%d%d%d%d",1,1,0,0);
	} else if(s1[2]==s2[2]+1||s2[2]==s1[2]+1){
		printf("%d%d%d%d",1,1,1,0);
	}	else{
		printf("%d%d%d%d",1,1,1,1);
	}
	return 0;
} 
