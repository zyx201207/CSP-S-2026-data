#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a[6]={0};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
	}
	
	if(a[1]==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		a[2]=1;
	}
	
	if(a[2]==1&&s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
		a[3]=1;
	}
	else
	if(a[2]==1&&s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'){
		a[3]=1;
	}
	
	if(a[3]==1){
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			a[4]=1;
		}
		else
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
			a[4]=1;
		}
	}
	printf("%d%d%d%d",a[1],a[2],a[3],a[4]);
	return 0;
	
} 
