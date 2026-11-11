 #include<iostream>
 #include<string.h>
 using namespace std;
 int main()
 {
     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
     char c1,s1,c2,s2;
     cin>>c1>>s1>>c2>>s2;
     if(c1=c2){
        if(strlen(c1)==strlen(c2)){
            cout<<"1111";
        }
        else
            cout<<"1110";
     }
     else
        cout<<"0000";
     return 0;
 }
