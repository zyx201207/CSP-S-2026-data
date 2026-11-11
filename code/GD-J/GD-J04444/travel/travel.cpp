#include<bits/stdc++.h>
using namespace std;
char a[100],b[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int car1,car2;
	cin>>car1>>a>>car2>>b;
	int sita,sitb;
	char type1,type2;
	sita=a[0]*10+a[1];
	type1=a[2];
	sitb=b[0]*10+b[1];
	type2=b[2];
	//同车厢 
	if(car1==car2){
		
		cout<<1;
		//同排 
		if(sita==sitb){
			
			cout<<1;
			//同侧 
			if((type1>='A'&&type1<='C'&&type2>='A'&&type2<='C') || (type1>='D'&&type1<='F'&&type2>='D'&&type2<='F')){
				cout<<1;
				if(type1>type2)swap(type1,type2);
				if(type2-type1==1){
					if(type2!='D'){cout<<1;}
					else cout<<0;
				}else cout<<0;
				
			}else cout<<"00";
			
		}
		else cout<<"000";
		
	} 
	else cout<<"0000";
		
	
	
	
	

	
	

	
	return 0;
} 
