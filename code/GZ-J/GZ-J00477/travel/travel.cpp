//GZ-J00477   程川奇 遵义市第16中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("treavel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    	else cout<<0;
    	if(s1[0]==s2[0]||s1[1]==s2[1])cout<<1;
    	else cout<<0;
  
   for(char i=1;i<=s1[i];i++){
   	if(s1[i]==s2[i])cout<<1;
   	if(s1[i]==s2[i+1]||s2[i]==s1[i+1])cout<<1;
   	if(s2[i]==s1[i+1]||s1[i]==s2[i+1])cout<<1;
	if(s1[i]=='C'||s2[i]=='D') cout<<0;
   	if(s2[i]=='C'||s1[i]=='D') cout<<0;
   }
  
   
   
   
  //02 01C 02 01A
 //02 01C 02 01D
 //02 02B 02 01A
//02 01A 03 01A
return 0;
 }

