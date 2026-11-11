#include<bits/stdc++.h>
using namespace std;
const int N=100050;
long long n,m,s=1;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long cnt[m+10],chu[N];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n-i+1;j++)
            if(chu[j]!=a[i]) chu[j]=a[j];
            else {
                for(int i1=1;i1<=j;i1++) chu[i1]=0;
            }
        for(int j=1;j<=m;j++){
            if(a[s]==j) cnt[j]++;
            s++;
        }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}


