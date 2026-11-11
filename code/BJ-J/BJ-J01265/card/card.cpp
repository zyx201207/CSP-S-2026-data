#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],t[300005],w[500005],wei,last[500005];
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(last[a[j]]){
                wei=last[a[j]]-1;
            }
            w[++wei]=a[j];
            last[a[j]]=wei;
        }
        for(int j=1;j<=wei;j++)t[w[j]]++;
        memset(last,0,sizeof last);
        memset(w,0,sizeof w);
    }
    for(int i=1;i<=m;i++)cout << t[i] << ' ';
    return 0;
}
