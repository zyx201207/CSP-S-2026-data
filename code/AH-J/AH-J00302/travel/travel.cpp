#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,q1,q2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<s1.size()-1;i++)
        q1+=s1[i];
    for(int i=0;i<s2.size()-1;i++)
        q2+=s2[i];
    char a=s1[2],b=s2[2];
    if(c1==c2){
        if(q1==q2){
            if((a<=67&&b<=67)||(a>=68&&b>=68)){
                if((a-b==1)||(b-a==1)){
                    cout<<1111;
                }else{
                    cout<<1110;
                }
            }else{
                cout<<1100;
            }
        }else{
            cout<<1000;
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
