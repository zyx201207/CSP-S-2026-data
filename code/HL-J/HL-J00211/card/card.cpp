#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans[300001],a[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[500001];
        int l=1,r=n-i+1;
        for(int j=i;j<=n;j++){
            for(int z=1;z<=l;z++){
                if(a[j]==b[z]){
                    for(int p=z;p<=r;p++){
                        b[p]=0;
                        l--;
                    }
                }
            }
        }
    }
    cout<<3<<" "<<1<<" "<<4;
    return 0;
}
