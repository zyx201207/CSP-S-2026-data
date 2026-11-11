#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int nt=1;
        int t[500005],k[300005];
        for(int j=i;j<=n;j++){
            if(k[a[j]]>0){
                for(int q=k[a[j]]+1;q<nt;q++){
                    k[t[q]]=0;
                    t[q]=0;
                }
                nt=k[a[j]]+1;
                continue;
            }
            t[nt]=a[j];
            k[a[j]]=nt;
            nt++;
        }
        for(int j=1;j<nt;j++){
            b[t[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}