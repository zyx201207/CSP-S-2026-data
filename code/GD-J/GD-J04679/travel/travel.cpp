#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		
		int line1=(s1[2]-'A')+1;
		int line2=(s2[2]-'A')+1;
		
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((line1<=3&&line2<=3)||(line1>3&&line2>3)){
				cout<<1;
				switch(line1){
					case 1:if(line2==2){cout<<1;}else{cout<<0;}break;
					case 2:if(line2==1||line2==3){cout<<1;}else{cout<<0;}break;
					case 3:if(line2==2){cout<<1;}else{cout<<0;}break;
					case 4:if(line2==6){cout<<1;}else{cout<<0;}break;
					case 5:cout<<0;break;
					case 6:if(line2==4){cout<<1;}else{cout<<0;}break;
				}
			}else{
				cout<<0<<0;
			}
			
		}else{
			cout<<0<<0<<0;
		}
		
	}else{
		cout<<0<<0<<0<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
