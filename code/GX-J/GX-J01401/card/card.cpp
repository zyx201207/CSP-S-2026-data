#include<bits/stdc++.h>
using namespace std;
//I love luogu/LuoGu , kkksc03 and chen_zhe;
//i cant speak chinese because i dont have shurufa;
//I ONLY CAN PIANFEN;
//<<I Can't Wait feat.GUMI>>
//I can't wait no mistake
//I'm in love like drug pick me up;
//These feelings never leave me heart
//love me love me ahhhh

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long ans[500005]={0};
    for(int i=1;i<=n;i++){
        long long tp;
        cin>>tp;
        ans[tp]++;
    }
    for(int i=1;i<=m;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<" ";
    }

    return 0;
}

