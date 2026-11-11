#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else{
        cout<<'1';
        if(s1.substr(0,2)!=s2.substr(0,2)) cout<<"000";
        else{
            cout<<'1';
            if(!(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'||s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D')) cout<<"00";
            else{
                cout<<'1';
                cout<<(abs(s1[2]-s2[2])==1);
            }
        }
    }
    return 0;
}
