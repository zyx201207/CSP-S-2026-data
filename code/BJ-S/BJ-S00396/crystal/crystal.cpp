#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int howmuch(){
    int ans=0;
    int s=a[2]-a[1],cnt=0;
    for(int i=1,j=0;i<=n&&m>=0;i++){
        j+=s;
        m-=j;
        ans++;
        //cout<<i<<" "<<j<<" "<<cnt<<" "<<m<<" "<<ans<<endl;
    }
    return ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    bool isgood=true;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]-a[i-1]!=a[2]-a[1]) isgood=false;
    }
    cout<<howmuch();
    return 0;
}
/*
♖♘♗♕♔♗♘♖
♙♙♙♙♙♙♙♙




♟♟♟♟♟♟♟♟
♜♞♝♛♚♝♞♜
chess.com
离线版（提示：左右脑互搏）
*/
