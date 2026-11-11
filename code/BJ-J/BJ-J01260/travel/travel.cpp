#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1;
    string c2,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<1;
        int c=0,s=0;
        for(int i=0;i<s2.size()-1;i++){
            s=s*10+(s2[i]-'0');
        }
        for(int i=0;i<c2.size()-1;i++){
            c=c*10+(c2[i]-'0');
        }
        if(c==s){
            cout<<1;
            char a=c2[2];
            char b=s2[2];
            if(a>b)swap(a,b);
            if((a=='A' && b=='B') || (a=='B' && b=='C') || (a=='A' && b=='C') || (a=='D' && b=='E')){
                cout<<1;
                if(!(a=='A' && b=='C')){
                    cout<<1;
                }else{
                    cout<<0;
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