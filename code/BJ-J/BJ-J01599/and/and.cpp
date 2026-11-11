#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int wei[35]={};
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=30;j++){
            if(a[i]&(1<<j)) wei[j]++;
        }
    }
    for(int i=30;i>=0;i--){
        if(wei[i]<m) continue;
        int k=0;
        for(int j=1;j<=n;j++){
            if(a[j]&(1<<i)) k++;
            else a[j]=0;
        }if(k>=m) ans+=1<<i;
    }
    cout<<ans;
    return 0;
}
