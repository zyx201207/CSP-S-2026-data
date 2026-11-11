#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int f[300];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    f['A']=f['B']=f['C']=1;
    f['D']=f['F']=2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(f[s1[2]]==f[s2[2]]){
                cout<<1;
                string t=s1+s2;
                t.erase(0,2);
                t.erase(1,2);
                sort(t.begin(),t.end());
                if(t=="AB"||t=="BC"||t=="DF") cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
