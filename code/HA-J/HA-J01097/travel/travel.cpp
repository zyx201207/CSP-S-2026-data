#include<bits\stdc++.h>
using namespace std;
	int c_1,c_2;
	string s_1,s_2;
	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	

	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2 and c_1<=17){
		cout<<1;
	
	if(s_1[0]==s_2[0] and s_1[1]==s_2[1]) {
	cout<<1;	
	

	
	
	if((s_1[2]=='A' and s_2[2]=='B')    or  (s_1[2]=='B' and s_2[2]=='C')   or   (s_1[2]=='D' and s_2[2]=='F')                           
	or                  (s_1[2]=='B' and s_2[2]=='A')    or  (s_1[2]=='C' and s_2[2]=='B')   or   (s_1[2]=='F' and s_2[2]=='D')    
	or (s_2[2]=='A' and s_1[2]=='B')    or  (s_2[2]=='B' and s_1[2]=='C')   or   (s_2[2]=='D' and s_1[2]=='F')            
	or     (s_2[2]=='B' and s_1[2]=='A')    or  (s_2[2]=='C' and s_1[2]=='B'   or   (s_2[2]=='F' and s_1[2]=='D')           )){
		
		cout<<11;
		return 0;
		
	} 
	
		if(    (s_1[2]=='A' and s_2[2]=='C')     or (s_2[2]=='A' and s_1[2]=='C')  or  (s_1[2]=='D' and s_2[2]=='F')    or   (s_1[2]=='F' and s_2[2]=='D')  
		or  (s_1[2]=='C' and s_2[2]=='A')     or (s_2[2]=='C' and s_1[2]=='A')  or  (s_1[2]=='F' and s_2[2]=='D')    or   (s_1[2]=='D' and s_2[2]=='F')        ){
		 cout<<10;	
		} else cout<<"00";
		
		
	}else cout<<"000";
	
	
		
		
		
		
	}else cout<<"0000";
	
	
	return 0;
}
