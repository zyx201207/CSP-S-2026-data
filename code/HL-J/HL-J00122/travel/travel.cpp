#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int sum=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<1;
    }else{
    cout<<"0000";
    return 0;
}
     for(int i=0;i<=1;i++){
        if(c2[i]==s2[i]){
            sum++;
        }
     }
     if(sum==2){
        cout<<1;
     }else{
     cout<<"000";
     return 0;
     }
     if((c2[2]>='A'&&c2[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D')){
        cout<<1;
     }else{
         cout<<"00";
         return 0;
     }
     if((c2[2]=='A'&&s2[2]=='B')||(c2[2]=='B'&&s2[2]=='C')||(c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D')){
        cout<<1;
        return 0;
     }else{
         cout<<0;
         return 0;
     }
    return 0;
}
