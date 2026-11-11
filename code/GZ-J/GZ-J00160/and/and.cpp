//GZ-J00160 贵阳市第三中学 严介谦
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int maxn=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int temp=(a[i]&a[j]&a[k]);
                maxn=max(maxn,temp);
            }
        }
    }cout<<maxn;
    return 0;
}
