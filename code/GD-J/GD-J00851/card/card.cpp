#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1919810];
bitset<1919810> b;
int ans[1919810];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int id=1;id<=n;id++){
        b.reset();
        for(int j=id;j<=n;j++){
            int las=j;
            for(int k=j-1;k>=id;k--){
                if(b[k]==0&&(a[k]==a[j])){
                    las=k;
                    break;
                }
            }
            for(int k=j-1;k>=las;k--)
                b[k]=1;
        }
        for(int j=id;j<=n;j++){
            if(!b[j])
                ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
/*
洛谷关注uid1063830谢谢喵

T4思维
11：01分，貌似想到了
11：26分，思路错了，决定暴力
*/