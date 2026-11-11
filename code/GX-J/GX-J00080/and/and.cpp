#include<bits/stdc++.h>
using namespace std;
long long a[200001];
bool z[200001][30];
bool cmp(int l,int r){
    return l>r;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.ans","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        bitset<30>f(a[i]);
        for(int j=0;j<30;j++)
            z[i][j]=f[j];
    }
    long long ans=a[1];
    for(int i=2;i<=m;i++)
        ans&=a[i];
    long long ans1=a[2];
    for(int i=3;i<=m;i++)
        ans1&=a[i];
    cout<<max(ans,ans1);
    return 0;
}
