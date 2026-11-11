#include<bits/stdc++.h>
using namespace std;
int ax,ap,bx,bp,s1=0,s2=0,s3=0,s4=0;
int ah,bh;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a;
	
	cin>>a;
	ax=(int)a-'0';
	cin>>a;
	ax=ax*10+(int)a-'0';
	cin>>a;
	ap=(int)a-'0';
	cin>>a;
	ap=ap*10+(int)a-'0';
	cin>>a;
	ah=(int)a-'A';
	
	cin>>a;
	bx=(int)a-'0';
	cin>>a;
	bx=bx*10+(int)a-'0';
	cin>>a;
	bp=(int)a-'0';
	cin>>a;
	bp=bp*10+(int)a-'0';
	cin>>a;
	bh=(int)a-'A';
	
	
	if(ax==bx){
		s1=1;
		if(ap==bp){
			s2=1;
			if(  ((ah==0||ah==1||ah==2)&&(bh==0||bh==1||bh==2))  ||  ((ah==3||ah==5)&&(bh==3||bh==5))  ){
				s3=1;
				if(!((ah==0&&bh==2)||(ah==2&&bh==0))){
					s4=1;
				}
			}
			
		}
	}
	cout<<s1<<s2<<s3<<s4;
	
}
