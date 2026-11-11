#include <bits/stdc++.h>
using namespace std;
char sc1[1],sc2[1],sz1[5],sz2[5],s[3],sc2a[1],sz2a[5],sz1a[5],sc2[a];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++){
		scanf("%c\n",&sc1[i]);
	}
	for(int j=0;j<4;j++){
		scanf("%c",&sz1[j]);
	}
	for(int i=0;i<3;i++){
		scanf("%c",&sc2[i]);
		sc2a[i]=sc2[i];
	}
	for(int i=0;i<3;i++){
		scanf("%c",&sz2[i]);
		sz2a[i]=sz2[i];
	}
	
	for(int i=0;i<1;i++){
		scanf("%c\n",&sc1[i]);
		sz1a[i]=sc1[i];
	}
	for(int j=0;j<3;j++){
		scanf("%c",&sz1[j]);
		
	}
	for(int i=0;i<4;i++){
		scanf("%c",&sc2[i]);
	
	}
	for(int i=0;i<2;i++){
		scanf("%c",&sz2[i]);
		
	}
	int m=(sc1[1]-'0')+((sc1[0]-'0')*10);
	int n=(sc2[1]-'0')+((sc2[0]-'0')*10);
	if(m!=n||(m==1||m==16||n==1||n==16)){
		s[0]='0';
	}else s[0]='1';
	for(int i=0;i<3;i++){
		printf("%c",sc1[i]);
	}
	
	if(sz1a[0]!=sz2a[0]||sz1a[1]!=sz2a[1]){
		s[1]='0';
	}else s[1]='1';
	int a=sz1a[2]-'1';
	int b=sz2a[2]-'1';
	if((max(a,b)==20&&(a+b)!=39)||max(a,b)==19){
		s[2]='0';
	}else s[2]='1';
	int c=a+b;
	if(((c==33||c==35)&&max(a,b)<19)||(max(a,b)==20&&c==39)){
		s[3]='1';
	}else s[3]='0';
	for(int i=0;i<4;i++){
		printf("%c",s[i]);
	}
	return 0;
}
