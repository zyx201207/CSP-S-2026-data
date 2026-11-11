#include<bits/stdc++.h>
using namespace std;

int n,m,a[50001],b[50001],ans[50001];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(b[a[i]]==0)b[a[i]]=i;
        else {
            for(int j=b[a[i]];j<i;j++){
                b[a[j]]=0;
            }
        }
        for(int j=1;j<=m;j++){
            if(b[a[i]]!=0)ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }

    return 0;
}
