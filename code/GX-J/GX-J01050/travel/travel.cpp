#include <iostream>
using namespace std;
	 string s1;
	 string s2;
	 int c1,c2;
	 string a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	
	cin>>c1>>s1>>c2>>s2;
	
	
	for(int i=0;i<=4;i++)
	{
	if(i==0)
	{
		if(c1==c2){
			a[i]="1";
			if(s2[0]==s1[0]&&s2[1]==s2[1]){
				a[i+1]=="1";
				if(int(s1[2])==int(s2[2])||int(s1[2])==int(s2[2]+1)||int(s1[2])==int(s2[2]+2)||int(s1[2]+1)==int(s2[2])||int(s1[2]+2)==int(s2[2])){
					a[i+2]=="1";
					if(s1[1]==s2[1])
						a[i+3]="1";
					else
						a[i+3]="0";
				}
				else
					a[i+2]=="0";
			if(s1[2]==s2[2]){
				if(int(s1[1])==int(s2[1]+1)||int(s1[1])==int(s2[1]-1))	a[i+3]="1";
				else    a[i+3]="0";
				
				
			
			}
		
		
		}
			else
				a[i+1]=="0";
    
			
				 
				 }
		}
		else	a[i]="0";
		continue;
	}		
	
	
	
	
	
	for(int j=0;j<=3;j++){
		cout<<a[j];
		}
	
	
	
	
	return 0;
	}
