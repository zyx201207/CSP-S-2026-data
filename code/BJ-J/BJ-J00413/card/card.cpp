#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],now[500010],place[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    for(int i=1;i<=n;++i){
        memset(now,0,sizeof(now));
        memset(place,-1,sizeof(place));
        int r=0;
        for(int j=i;j<=n;++j){
            if(place[a[j]]==-1||place[a[j]]>r){
                r++;
                now[r]=a[j];
                place[a[j]]=r;
            }
            else{
                for(int k=place[a[j]]+1;k<=r;++k){
                    place[now[k]]=-1;
                }
                r=place[a[j]];
            }
            //cout << r <<" ";
        }
        //cout <<"\n";
        for(int j=1;j<=r;++j){
            //cout << now[j] <<" ";
            ans[now[j]]++;
        }
        //cout <<"\n";
    }
    // cout <<"\n";
    for(int i=1;i<=m;++i){
        cout << ans[i] << " ";
    }
    cout <<"\n";
    return 0;
}

