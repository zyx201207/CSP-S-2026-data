#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,s;
    cin>>a;
    string q,w;
    cin>>q;
    cin>>s>>w;
    int z[5];
    for(int i=1;i<=q.size();i++){
        if(q[i]>='0'&&q[i]<='9'){
            z[i]=q[i];
        }
    }
    int pol=0;
    for(int i=1;i<=1;i++){
        pol+=z[i]*10;
    }
    for(int i=2;i<=2;i++){
        pol+=z[i];
    }
    int l[5];
    for(int i=1;i<=w.size();i++){
        if(w[i]>='0'&&w[i]<='9'){
            l[i]=w[i];
        }
    }
    int zd=0;
    for(int i=1;i<=1;i++){
        zd+=l[i]*10;
    }
    for(int i=2;i<=2;i++){
        zd+=l[i];
    }
    char qq,ww;
    for(int i=1;i<=q.size();i++){
        if(q[i]>='A'&&q[i]<'G'&&q[i]!='E'){
            qq=q[i];
        }
    }
    for(int i=1;i<=w.size();i++){
        if(w[i]>='A'&&w[i]<'G'&&q[i]!='E'){
            ww=w[i];
        }
    }
    if(a==s){
        cout<<1;
        if(pol=zd){
            cout<<1;
            if((qq=='A'&&ww=='B')||(qq=='A'&&ww=='C')||(qq=='B'&&ww=='C')||(qq=='B'&&ww=='A')||(qq=='C'&&ww=='B')||(qq=='C'&&ww=='A')||(qq=='F'&&ww=='D')||(qq='D'&&ww=='F')){
                cout<<1;
                if((qq=='A'&&ww=='B')||(qq=='B'&&ww=='C')||(qq=='B'&&ww=='A')||(qq=='C'&&ww=='B')||(qq=='F'&&ww=='D')||(qq=='D'&&ww=='F')){
                    cout<<1;
                    return 0;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        else{
            cout<<0<<0<<0;
            return 0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}
