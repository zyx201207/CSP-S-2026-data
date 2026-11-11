#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
string a1,a2,b1,b2;
void solve(){
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<"1";
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            cout<<"1";
            char x=a2[2],y=b2[2];
            if(x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='C'||x=='B'&&y=='A'||x=='C'&&y=='A'||x=='C'&&y=='B'||x=='D'&&y=='F'||x=='F'&&y=='D'){
                cout<<"1";
                if(x=='A'&&y=='B'||x=='B'&&y=='C'||x=='B'&&y=='A'||x=='C'&&y=='B'||x=='D'&&y=='F'&&x=='F'&&y=='D'){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else{
                cout<<"00";
            }
        }
        else {
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t=1;
    while(t--) solve();
    return 0;
}
