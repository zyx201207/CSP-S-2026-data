#include <bits/stdc++.h>

using namespace std;
int cnt=1;
int tab[500005],s[300005],a[500005],ans[300005];
int findx(int x){
    for(int i=1;i<=cnt;i++){
        if(tab[i]==x) return i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int j=n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[a[i]]==1){
                int l=findx(a[i]);
                int t=cnt;
                for(int k=l;k<=t;k++){//nazoupai
                    tab[k]=0;
                    cnt--;
                }
            }
            tab[cnt]=a[i];//fangpai
            cnt++;
            s[a[i]]=1;
            for(int z=1;z<=cnt;z++) cout<<tab[z]<<" ";
            cout<<endl;
        }

        for(int j=1;j<=cnt;j++){
            ans[tab[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
