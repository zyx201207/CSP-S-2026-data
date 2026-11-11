#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int zc1,zc2,zp1,zp2,ans,g1,g2;
char zs1,zs2;
int jd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    zc1=c1[0]*10+c1[1];
    zc2=c2[0]*10+c2[1];
    zp1=s1[0]*10+s1[1];
       zp2=s2[0]*10+s2[1];
       zs1=s1[2];
       zs2=s2[2];
       if(zc1==zc2){
       	cout<<"1";
       	ans++;
	   }else{
	   	cout<<"0";
	   }
	     if(zp1==zp2 && ans==1){
       	cout<<"1";
       	ans++;
	   }else{
	   	cout<<"0";
	   }
	     if(zs1=='A' || zs1=='B' || zs1== 'C'){
       	g1=1;
	   }else{
	   	g1=2;
	   }
	     if(zs2=='A' || zs2=='B' || zs2== 'C'){
       	g2=1;
	   }else{
	   	g2=2;
	   }
	     if(g1==g2 && ans==2){
       	cout<<"1";ans++;
	   }else{
	   	cout<<"0";
	   }
	   if(ans==3){
	   	if(zs1=='A'&&zs2=='B' || zs1=='B'&&zs2=='C' || zs1=='D'&&zs2=='F'){
	   		cout<<"1";
	   		jd=1;
		   }
	   }
	   if(jd==0){
	   	cout<<"0";
	   }
	return 0;
}
