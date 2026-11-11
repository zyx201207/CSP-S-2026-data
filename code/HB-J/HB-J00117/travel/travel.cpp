#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    char sc1,sc2;
    cin>>c1>>s1>>sc1>>c2>>s2>>sc2;
    if(c1==c2){
        if(s1==s2){
            if(!((sc2=='C'&&sc1=='D')||(sc1=='C'&&sc2=='D'))){
                if(abs(sc1-sc2)==1){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    
}
