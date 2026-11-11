#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[4]={0,0,0,0};
int cnt;
int flag;
void check(){
	if((c1==c2)&&cnt!=97&&cnt!=104){
		a[0]=1;
	}
	//TONGYIPAI
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]=1;
		flag=1;
	}
	if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'&&flag){
		a[2]=1;
		flag=2;
	}
	if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'&&flag){
		a[2]=1;
		flag=2;
	}//XIANGLIN
	if((s1[2]==s2[2]+'1'-48||s2[2]==s1[2]+'1'-48)&&flag==2){
		a[3]=1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cnt=c1[0]+c1[1];
	check();
	
	for(int i=0;i<4;i++){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
