#include<bits/stdc++.h>
using namespace std ;
string c1,s1,c2,s2 ;
bool chk(char o1,char o2){
	if((o1=='A'||o1=='B'||o1=='C')&&(o2=='A'||o2=='B'||o2=='C'))
		return true ;
	if((o1=='F'||o1=='D')&&(o2=='D'||o2=='F'))
		return true ;
	return false ; 
}
int main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin>>c1>>s1>>c2>>s2 ;
	int cx1=0,cx2=0,sx1=0,sx2=0 ;
	char o1,o2 ;
	for( int i=0 ; i<c1.size() ; i++ )
		cx1=cx1*10+(c1[i]-'0') ;
	for( int i=0 ; i<c2.size() ; i++ )
		cx2=cx2*10+(c2[i]-'0') ;
	for( int i=0 ; i<s1.size()-1 ; i++ )
		sx1=sx1*10+(s1[i]-'0') ;
	o1=s1[s1.size()-1] ;
	
	for( int i=0 ; i<s2.size()-1 ; i++ )
		sx2=sx2*10+(s2[i]-'0') ;
	o2=s2[s2.size()-1] ;
	string ans="" ;
	if(cx1==cx2){
		ans+='1' ;
		if(sx1==sx2){
			ans+='1' ;
			if(chk(o1,o2)){
				ans+='1' ;
				if(abs(int(o1)-int(o2))<=1) 
					ans+='1' ;
				else ans+='0' ;
			}else
				ans+="00" ;
		}else ans+="000" ;
	}else ans+="0000" ;
	cout<<ans ;
} 
