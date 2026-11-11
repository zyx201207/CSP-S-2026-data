#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m,a[N],t[M],sta[N],topp,ans[M];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int j = 1;j<=n;j++){
        topp=1;
        for(int i = 1;i<=m;i++) t[i]=0;
        for(int i = j;i<=n;i++){
            if(t[a[i]]){
                int num=t[a[i]];
                for(int k = t[a[i]];k<topp;k++){
                    t[sta[k]]=0;
                }
                topp=num;
            }
            t[a[i]]=topp;
            sta[topp++]=a[i];
        }
        for(int i = 1;i<=m;i++){
            if(t[i]){
                ans[i]++;
            }
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}
