#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,ans;
long long m,a[N],qzh[N];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    int k = 1;
    for(int i = 1;i<=n;i++){
        while(k<=i){
            if(a[i]*(i-k+1)-(qzh[i]-qzh[k-1])<=m) break;
            else k++;
        }
        if(a[i]*(i-k+1)-(qzh[i]-qzh[k-1])<=m){
            ans=max(ans,i-k+1);
        }
    }
    cout<<ans;

    return 0;
}
