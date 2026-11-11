#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,p[6]={1,1,1,0,0,0};
char s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>s1>>b>>d>>s2;
    if(a!=b){
        cout<<"0000";
    }else{
        if(c!=d){
            cout<<"1000";
        }else{
            if(p[s1-'A']!=p[s2-'A']){
                cout<<"1100";
            }else{
                if(abs(s1-s2)>1){
                    cout<<"1110";
                }else{
                    cout<<"1111";
                }
            }
        }
    }
    return 0;
}