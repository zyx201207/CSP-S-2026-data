#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    // Isn't froepen,it's freopen
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1.substr(0,2)!=s2.substr(0,2)){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs(s1[2]-s2[2])==1&&(!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))) cout<<1;
    else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<1;
    else cout<<0;
    return 0;
}