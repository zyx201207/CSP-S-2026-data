#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,max1=-1;
    long long a[500005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<=a[n];i++){
        int cmp[n]={0},l=m,cnt=-1,mx=0;
        for(int j=1;j<=n;j++){
            if(a[j]>i) continue;
            cmp[j]=i-a[j];
            cnt++;
        }
        for(int j=cnt;j>=0;j--){
            if(cmp[j]<=l){
                l-=cmp[j];
                mx++;
            }
            else break;
        }
        max1=max(max1,mx);
    }
    cout<<max1;
    return 0;
}
