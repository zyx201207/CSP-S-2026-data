#include<bits/stdc++.h>
#define int long long
using namespace std;
string r,l,x,y;
int len;
bool ok=false;
void solve(){
    cin>>r>>l>>x>>y;
    if(r!=x){cout<<"0000";return;}
    else{
        cout<<1;
        for(int i=0;i<(int)l.length()-1;i++){
            if(l[i]!=y[i]){
                cout<<"000";
                return;
            }
        }cout<<1;
        len=(int)y.length()-1;
        if((y[len]=='A'||y[len]=='B'||y[len]=='C')&&(l[len]=='A'||l[len]=='B'||l[len]=='C')){
            cout<<1;ok=true;
            if((y[len]=='A'&&l[len]=='B')||(l[len]=='A'&&y[len]=='B')||(y[len]=='B'&&l[len]=='C')||(l[len]=='B'&&y[len]=='C')){cout<<1;return;}
        }if((y[len]=='D'&&l[len]=='F')||(y[len]=='D'&&l[len]=='F')){cout<<"11";return;}
        else if(ok){cout<<"0";return;}
        cout<<"00";
    }

}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    solve();
}
