#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
long long a[N],b[N],sum[N];
int main(){
    freopen("card.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long p;
    for(int i=n;i>=1;i--){
        p=i;
        for(int j=i;j<=n;j++){
            if(a[j]==a[i]){
                p=j;
            }
        }
        b[i]=p;
        while(p<n){
            sum[a[p]]++;
            p=b[p+1];
        }
    }
    sum[a[n]]=n;
    freopen("card.out","w",stdout);
    for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
}
