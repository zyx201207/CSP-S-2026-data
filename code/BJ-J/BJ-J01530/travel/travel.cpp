#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
map<char,int> mp;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    mp['A']=1;
    mp['B']=3;
    mp['C']=5;
    mp['D']=2;
    mp['F']=4;
    if(a==c){
        cout<<1;
        if(10*(b[0]-'0')+b[1]-'0'==10*(d[0]-'0')+d[1]-'0'){
            cout<<1;
            if(mp[b[2]]%2==mp[d[2]]%2){
                cout<<1;
                if(abs(mp[b[2]]-mp[d[2]])==2){
                    cout<<1;
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
