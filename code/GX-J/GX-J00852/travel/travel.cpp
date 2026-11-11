#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1,c2;
string s1,s2;
cin>>c1>>s1>>c2>>s2;
string s01="",s02="";
char s3=s1[2],s03=s2[2];
for(int i=0;i<2;i++){
    s01+=s1[i];
}
for(int i=0;i<2;i++){
    s02+=s2[i];
}
if(c1==c2){
    cout <<1;
    if(s02==s01){
        cout<<1;
        if(s3<=67&&s03<=67||s3>67&&s03>67){
            cout <<1;
            if(s3==65&&s03==66){
                cout<<1;
            }
            else if(s3==66&&s03==s3+1||s3==66&&s03==s3-1){
                cout<<1;
            }
            else if(s3==67&&s03==66){
                cout <<1;
            }
            else if(s3==68&&s03==69||s3==69&&s03==68){
                cout<<1;
            }
            else{
                cout <<0;
            }
        }
        else{
             cout <<0<<0;
        }
    }
    else{
        cout<<0<<0<<0;
    }
    }
else{
    cout<<0<<0<<0<<0;
}
return 0;
}
