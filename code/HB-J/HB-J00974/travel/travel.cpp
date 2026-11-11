#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    bool f=0;
    int n=s1.size();
    for(int i=0;i<n-1;i++){
        if(s1[i]!=s2[i]){
            f=1;
            break;
        }
    }
    if(!f){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(s1[n-1]<='C'&&s2[n-1]<='C'){
        cout<<1;
        if(abs(s1[n-1]-'A'-(s2[n-1]-'A'))<2) cout<<1;
        else cout<<0;
    }
    else if(s1[n-1]>'C'&&s2[n-1]>'C'){
        cout<<11;
    }
    else cout<<"00";
    return 0;
}
