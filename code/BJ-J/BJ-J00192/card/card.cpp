#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int n,m,a[500005],ai[300005],ans[300005]={0},t=0;
    bool f=false;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ai[a[j]]++;
            if(ai[a[j]]>1){
                t=a[j];
                for(int k=1;k<j;k++){
                    if(f){
                        ai[a[k]]=0;
                        continue;
                    }
                    if(a[k]==t){
                        f=true;
                        ai[a[k]]=0;
                    }
                }
                f=false;
                ai[a[j]]++;
            }
        }
        for(int k=1;k<=m;k++){
            if(ai[k]) ans[k]++;
            ai[k]=0;
        }
        a[i]=0;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
