#include <bits/stdc++.h>
#include<iostream>
using namespace std;
long long n,m,a[10000000],l,sum[10000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int k=1;k<=n;k++)
    {
        l=k;
        for(int i=k+1;i<=n;i++)
        {

            for(int j=l;j<i;j++)
            {
                if(a[j]==a[i])
                {
                l=i;
                }
            }

        }
        for(int i=1;i<=m;i++){
            for(int j=l;j<=n;j++)
            {
                if(a[j]==i){
                sum[i]++;
                break;
                }
            }


        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
