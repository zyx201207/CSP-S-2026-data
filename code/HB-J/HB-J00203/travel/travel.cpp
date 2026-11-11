#include<bits/stdc++.h>
using namespace std;
int a,b;
char c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a;
    cin>>s1;
    c1=s1[2];
    s1[2]=0;
    cin>>b;
    cin>>s2;
    c2=s2[2];
    s2[2]=0;
    if(a==b){
        if(s1==s2){
            if( ((c1=='F'||c1=='D')&&(c2=='F'||c2=='D')) || ((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')) ){
                if(abs(c1-c2)==1){
                    cout<<"1111";
                    return 0;
                }
                else{
                    cout<<"1110";
                }
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    else{
        cout<<"0000 ";
        return 0;
    }
    return 0;
}
