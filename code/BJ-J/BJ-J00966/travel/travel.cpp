#include<bits/stdc++.h>
using namespace std;
char s[20];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

   for(int i=1;i<=10;i++)cin>>s[i];
   int a1=(s[1]-'0')*10+(s[2]-'0');
   int a2=(s[6]-'0')*10+(s[7]-'0');
   if(a1==a2){
        cout<<1;
   }
   else{
    cout<<"0000";
    return 0;
   }
   a1=(s[3]-'0')*10+(s[4]-'0');
   a2=(s[8]-'0')*10+(s[9]-'0');
   if(a1==a2)cout<<1;
   else{
    cout<<"000";
    return 0;
   }
   char c1=s[5],c2=s[10];
   if((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C'))cout<<1;
   else if ((c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))cout<<1;
   else{
       // cout<<"AAA";
    cout<<"00";
    return 0;
   }
   if((c1=='A'||c1=='B')&&(c2=='A'||c2=='B'))cout<<1;
   else if((c1=='C'||c1=='B')&&(c2=='C'||c2=='B'))cout<<1;
   else if((c1=='D'&&c2=='F')||(c1=='F'&&c2=='D'))cout<<1;
   else cout<<0;
    return 0;
}
