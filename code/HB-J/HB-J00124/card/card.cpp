#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int n,m,a[N],path[N],ans[N];

namespace subtask1{
    void solve(){
        for(int i=1;i<=n;i++){
            int len=0;
            for(int j=i;j<=n;j++){
                int flag=0;
                for(int k=1;k<=len;k++){
                    if(path[k]==a[j]){
                        flag=k;
                        break;
                    }
                }
                if(flag!=0){
                    len=flag;
                }else{
                    len++;
                    path[len]=a[j];
                }
            }
            for(int j=1;j<=len;j++) ans[path[j]]++;
        }
        for(int i=1;i<=m;i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n<=5000 && m<=3000){
        subtask1::solve();
    }
    return 0;
}
//g++ -o card card.cpp -O2 -std=c++14 -static
/*
namespace subtask1{
    void solve(){
        for(int i=1;i<=n;i++){
            unordered_map<int,int> vis;
            int len=0;
            for(int j=i;j<=n;j++){
                if(!vis.count(a[j]) || vis[a[j]]>len){
                    len++;
                    vis[a[j]]=len;
                    path[len]=a[j];
                }else{
                    len=vis[a[j]];
                    path[len]=a[j];
                }
            }
            for(int j=1;j<=len;j++) ans[path[j]]++;
        }
        for(int i=1;i<=m;i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}
*/