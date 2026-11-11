#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char k,p1,p2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>k;
        c1*=10;
        c1+=(k-48);
    }
    for(int i=1;i<=2;i++){
        cin>>k;
        s1*=10;
        s1+=(k-48);
    }
    cin>>p1;
    for(int i=1;i<=2;i++){
        cin>>k;
        c2*=10;
        c2+=(k-48);
    }
    for(int i=1;i<=2;i++){
        cin>>k;
        s2*=10;
        s2+=(k-48);
    }
    cin>>p2;
    if(c1==c2){
        cout<<"1";
        if(s1==s2){
            cout<<"1";
            if((p1>='A'&&p1<='C'&&p2>='A'&&p2<='C')||((p1=='D'||p1=='F')&&(p2=='D'||p2=='F'))){
                cout<<"1";
                if(abs((int)(p2-p1))==1&&(!(p1=='C'&&p2=='D')||(p1=='D'&&p2=='C'))){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
