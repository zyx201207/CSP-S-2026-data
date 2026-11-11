#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
bool tp=0,tp1=0,tp2=0;
string c1,c2,s1,s2;
cin>>c1>>s1;
cin>>c2>>s2;
if(c1==c2&&c1!="16"&&c1!="01"){
    cout<<'1';
    tp1=1;}
else{
    cout<<'0';
}
if(s2[0]==s1[0]&&s2[1]==s1[1]&&tp1==1)
 {
cout<<'1';
tp2=1;
 }
else{
    cout<<'0';
    }

if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(s2[2]=='A'&&tp2==1||s2[2]=='B'&&tp2==1||s2[2]=='C'&&tp2==1){
            cout<< '1';tp=1;

        }
        else{
            cout<<'0';
            }
}
else{
    if(s1[2]=='D'&&tp2==1||s2[2]=='F'&&tp2==1){
      cout<< '1';
      tp=1;
        }
        else{
            cout<<'0';

            }}
        if(s1[2]-s2[2]==1&&tp==1||s1[2]-s2[2]==-1&&tp==1)
        {
            cout<<'1';

        }
        else {
            cout<<'0';
        }

return 0;
}
