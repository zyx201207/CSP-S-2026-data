/*
in:
4 3
1 2 1 3
out:
3 1 4
*/
#include<bits/stdc++.h>
using namespace std;

const int maxN=2e5+5;

int n,m;

int a[maxN],b[maxN],cnt[maxN];

bool mark[maxN];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(mark,0,sizeof mark);
        for(int j=1;j<=n;j++)
            b[i]=a[i];
        for(int j=i;j<n;j++){
            for(int k=j+1;k<=n;k++)
                if(b[i]==b[j]){
                    for(int l=i+1;l<=j;l++)
                        b[l]=0;
                }
        }
        for(int j=1;j<=n;j++){
            mark[b[j]]=1;
        }
        for(int j=1;j<=m;j++)
            if(mark[j])
                cnt[j]++;
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}
