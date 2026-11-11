#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],b[500000],t[500000],s[500000],sum[500000];
void em(int l.int r){
    for(int i=l;i<=r;i++) t[i]=0;
}
void allem(){
    for(int i=1;i<=n;i++){
        b[i]=t[i]=s[i]=0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    int h=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                em(b[a[j]]+1,h);
                h=b[a[j]];
                continue;
            }
            b[a[j]]=++h;
            t[h]=a[j];
        }
        for(int j=1;j<=n;j++){
            if(t[j]) s[t[j]]=1;
        }
        for(int j=1;j<=n;j++){
            if(s[j]) sum[j]++;
        }
        allem();
    }
    for(int i=1;i<=n;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}