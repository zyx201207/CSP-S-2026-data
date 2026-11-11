#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,sum=0,a[1000005];
    long long m,w[100005],ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
            }
        }
    }

    int mans=0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-1;j++){
            w[j]=a[i+1]-a[j];
            ans+=w[j];
        }
        if(ans<=m){
            mans=max(mans,i);
            ans=0;
        }
    }
    if(mans!=0){
        mans+=1;
    }
    sum+=mans;
    cout<<sum;
    return 0;
}
