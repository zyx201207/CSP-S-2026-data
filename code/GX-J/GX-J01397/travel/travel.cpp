#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cx1,cx2,a1,a2;
    char s1,s2;
    cin>>cx1>>a1;
    cin>>s1;
    cin>>cx2>>a2;
    cin>>s2;
    if(cx1!=cx2){cout<<"0000";
        return 0;}

    else
       cout<<"1";
    if(a1!=a2){
	   cout<<"000";
	    return 0;}
	 else{
	  cout<<"1";}

        if(s1+1||s1-1!=s2)
       {
          cout<<"0";return 0;}
         else{
           cout<<"1";
       }
    }
    return 0;
}
