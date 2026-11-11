#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,n;

int main (){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
//	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
    cin >>c1>>s1>>c2>>s2;
    if (c1==c2) {
	n+="1";
    if (s1[0]+s1[1]==s2[0]+s2[1]){
    n+="1"; 
    if ((s1[2]<='C'&&s2[2]<='C'&&s1[2]>='A'&&s2[2]>='A')||(s1[2]>='D'&&s2[2]>='D'&&s1[2]<='F'&&s2[2]<='F')){
   	n+="1";
    if (abs(s1[2]-s2[2])==1)n+="1";
    else n+="0";
    }
    else n+="00";
    }
    else n+="000";
	}else n+="0000";
   // printf ("%s",n);
   cout <<n;
	return 0;
} 
