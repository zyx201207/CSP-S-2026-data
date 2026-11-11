#include <bits/stdc++.h>
using namespace std;

char t[20];
string c1,c2;
string s1,s2;
bool a[5];

inline void print(){
	for(int i=1;i<=4;i++){
		printf("%d",a[i]);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",t);
	c1=t;
	scanf("%s",t);
	s1=t;
	scanf("%s",t);
	c2=t;
	scanf("%s",t);
	s2=t;
	
	if(c1==c2){
		a[1]=1;
	}
	else{
		print();
		return 0;
	}
	if(s1[1]==s2[1] && s1[0]==s2[0]){
		a[2]=1;
	}
	else{
		print();
		return 0;
	}
	if((s1[2]=='D' && s2[2]=='C' )||(s1[2]=='D' && s2[2]=='C')){
		print();
		return 0;
	}
	else{
		a[3]=1;
	}
	if((s1[2]==(s2[2]+1)) || (s1[2]==(s2[2]-1)))
		a[4]=1;
	print();
	return 0;
		
}
