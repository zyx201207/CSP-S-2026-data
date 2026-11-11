#include <bits/stdc++.h>

using namespace std;
int n,m,a[600000],o[600000],l[500000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            o[j]=a[j];
        }
        for(int j=i;j<=n;j++){
            for(int p=i+1;p<=n;p++){
                if(o[j]==o[p]){
                    for(int q=j;q<p;q++)
                        o[q]=-1;
                }
            }
        }
        for(int j=i;j<=n;j++){
            for(int p=1;p<=m;p++){
                if(o[j]==p)
                    l[p]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<l[i]<<" ";
    }
    return 0;
}
