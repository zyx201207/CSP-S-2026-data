#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string a1,s1,a2,s2;
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2) {
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            string d=s1.substr(2,1);
            string f=s2.substr(2,1);
            if((d=="A"||d=="B"||d=="C")&&(f=="A"||f=="B"||f=="C") || (d=="D"||d=="F")&&(f=="D"||f=="F")){
                cout<<1;
                if((d=="D"||d=="F")&&(f=="D"||f=="F")) cout<<1;
                else if(d=="A"&&f=="B"||d=="B"&&f=="C"||d=="B"&&f=="A"||d=="C"&&f=="B"){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
