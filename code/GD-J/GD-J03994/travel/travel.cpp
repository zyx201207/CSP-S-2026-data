#include<bits/stdc++.h>
using namespace std ;
string c1,s1,c2,s2  ;
char a=  '1' ;
char b =  '0' ;
string s ;

int main(){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    cin >> c1 >> s1 >> c2 >> s2 ; //c1chexianghao  s1wzuoweihao c2changxianghao s2zuoweihao
    int len = c1.size();
    int len1 = s1.size() ;
    int len2 = c2.size() ;
    int len3 = s2.size();
	
    if(c1 == c2){
        for(int i = 0 ; i <= len1 ; i ++ ){
        	for(int i = 0 ; i <= len3 ;  i ++ ){
        		if(s1[i] == s2[i]){
        		s+=a;
					break ; 
				
				}if(s1[i] == 'A' && s2[i] == 'B') {
					s+=a; 
					break ; 
				}
				if(s1[i] == 'A'&& s2[i] == 'C'){
					s+=b;
					break;
				}
				}
					
				}
			}
			else{
				for(int i  = 1 ; i<= 4;  i++ ){
					s+=b  ;
				}
				 
			}
			cout << s; 
		}
    
    

