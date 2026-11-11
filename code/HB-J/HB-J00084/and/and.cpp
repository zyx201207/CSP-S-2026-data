#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long maxn=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long n,m;
    cin>>n>>m;
    int i=1;
    while(true){
        cin>>a[i];
        i++;
        if(i==n)    break;
    }

    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
    }
    else if(m==2){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
    else{
        cout<<0;
        return 0;
    }
    cout<<maxn;
    return 0;
}
