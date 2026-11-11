#include<bits/stdc++.h>
using namespace std;
long long n,m;long long a[200010],b[200010],c[200010];
long long fsd(long long x){
    long long h=x;
    for(int i=0;i<=n;i++)b[i]=0;
    for(int i=x;i<=n;i++){
        if(b[a[i]]==0)b[a[i]]=1;
        else h=i;
    }
    return h;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    } long long p=1;
    for(int i=1;i<=n;i++){
        long long k=fsd(p);
        for(int j=k;j<=n;j++){
            c[a[j]]++;
        }
        p++;
    }
    for(int i=1;i<=m;i++)cout<<c[i]<<" ";
    return 0;
}