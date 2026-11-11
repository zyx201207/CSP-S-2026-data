#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
string c1,s1,c2,s2,a,b,c,d;
void solve(){
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++){
        a+=s1[i];
        b+=s2[i];
    }
    c=s1[2];
    d=s2[2];
        cout<<"1";
        if(a==b){
            cout<<"1";
            if(c=="C"&&d=="D"||c=="D"&&d=="C"){
                cout<<"00";
            }else{
                cout<<"1";
                if(c=="A"&&d=="B"||c=="B"&&d=="A"||c=="B"&&d=="C"||c=="C"&&d=="B"||c=="E"&&d=="F"||c=="F"&&d=="E"){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
        return;
    }

}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
