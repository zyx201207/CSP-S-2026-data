#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,k1,k2;
    cin>>s1>>s2>>k1>>k2;
    if(s1==k1){
        cout<<1;
        if(s2[0]==k2[0]&&s2[1]==k2[1]){
            cout<<1;
            char r1=s2[2],r2=k2[2];
            bool p1=(r1=='A'||r1=='B'||r1=='C')&&(r2=='D'||r2=='F');
            bool p2=(r2=='A'||r2=='B'||r2=='C')&&(r1=='D'||r1=='F');
            if(!(p1||p2)){
                cout<<1;
                int s=abs(r1-r2);
                bool s1=(r1=='C')&&(r2=='D');
                bool s2=(r2=='C')&&(r1=='D');
                bool g1=(r1=='F')&&(r2=='D');
                bool g2=(r2=='F')&&(r1=='D');
                if((s==1&&!(s1||s2))||(g1||g2)){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else
                cout<<"00";
        }else
            cout<<"000";
    }else
        cout<<"0000";

    return 0;
}