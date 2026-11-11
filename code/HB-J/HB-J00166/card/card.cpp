#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],p,num[300005];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    int card[n+5];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int mm=1;mm<=i;mm++)
            {
                if(card[mm]==a[j]){
                    for(int abc=mm;abc<=n;abc++)card[abc]=0;
                    p=mm;
                    break;
                }
                p=j;
            }
            card[p]=a[j];
        }
        for(int j=1;j<=p;j++)num[card[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<num[i]<<' ';
    return 0;
}
