#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    int a=a2.size()-1;
    int b=b2.size()-1;
    for(int i=0;i<a;i++){
        if(a2[i]!=b2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    if((a2[a]=='A'&&b2[b]=='B')||(a2[a]=='A'&&b2[b]=='C')||(a2[a]=='B'&&b2[b]=='C')||(a2[a]=='D'&&b2[b]=='F')||(a2[a]=='B'&&b2[b]=='A')||(a2[a]=='C'&&b2[b]=='A')||(a2[a]=='C'&&b2[b]=='B')||(a2[a]=='F'&&b2[b]=='D'))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((a2[a]=='A'&&b2[b]=='B')||(a2[a]=='B'&&b2[b]=='C')||(a2[a]=='D'&&b2[b]=='F')||(a2[a]=='B'&&b2[b]=='A')||(a2[a]=='C'&&b2[b]=='B')||(a2[a]=='F'&&b2[b]=='D'))cout<<1;
    else cout<<0;
    return 0;
}