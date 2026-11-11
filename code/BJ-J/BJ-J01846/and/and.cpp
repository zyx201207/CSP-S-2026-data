#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,B=31;
int n,m,mi[B],a[N][B],ans[B],mp[N],kkk=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    mi[0]=1;
    for(int i=1;i<B;i++)mi[i]=mi[i-1]*2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=B-1;j>=0;j--){
            if(mi[j]<=x){
                a[i][j]=1;
                x-=mi[j];
            }else a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)mp[i]=1;
    for(int j=B-1;j>=0;j--){
        int sum=0;
        for(int i=1;i<=n;i++)if(a[i][j]==1&&mp[i]==1)sum++;
        if(sum>=m){
            for(int i=1;i<=n;i++)if(a[i][j]==0)mp[i]=0;
            ans[j]=1;
        }else ans[j]=0;
    }
    for(int i=0;i<B;i++)kkk+=(mi[i]*ans[i]);
    cout<<kkk<<'\n';
    return 0;
}
