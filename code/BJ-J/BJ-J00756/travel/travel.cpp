#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    char a21[2],b21[2],n,m;
    for(int i=0;i<=b1.length();i++){
        if(b1[i]<='9' && b1[i]>='0')
            a21[i]=b1[i];
    }
    for(int i=0;i<=b2.length();i++){
        if(b2[i]>='0' && b2[i]<='9')
            b21[i]=b2[i];
    }
    m=b1[2],n=b2[2];
    if(a1==a2){
        cout<<'1';
        if(a21[0]==b21[0] && a21[1]==b21[1]){
            cout<<'1';
            if(('A'<=m && m<='C')&&('A'<=n && n<='C') || ((m=='D' || m=='F')&&(n=='D' || n=='F')))
                cout<<'1';
            else
                cout<<'0';
            if((m=='A'&& n=='B')|| (m=='B' && (n=='A' || n=='C')) || (m=='C' && n=='B') || (m=='D' && n=='F') || (m=='F' && n=='D') )
                cout<<'1';
            else
                cout<<'0';
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}