#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
string c1,c2,s1,s2;
int a[N];
int t(string x){
    return signed(x[0]-'0')*10+signed(x[1]-'0');
}
signed main(){
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(t(s1)==t(s2)){
            cout<<1;
            if(signed(s1[2])<=67&&signed(s2[2])<=67 || signed(s1[2])>67&&signed(s2[2])>67){
               cout<<1;
               if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='B'&&s2[2]=='C' || s1[2]=='B'&&s2[2]=='A' || s1[2]=='C'&&s2[2]=='B' || s1[2]=='F'&&s2[2]=='D' || s1[2]=='D'&&s2[2]=='F') cout<<1;
               else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }
    else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
