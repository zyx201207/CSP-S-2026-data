#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool allbit(int x){
    while(x){
        if(x&1==0)return 0;
        x>>1;
    }
    return 1;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int M=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        M=max(a[i],M);
    }
    if(m==1){
        cout<<M;
        return 0;
    }
    if(m==n){
        int ans=a[0];
        for(int i=1;i<n;i++)ans = ans&a[i];
        cout<<ans;
        return 0;
    }
    if(allbit(M)){
        cout<<M;
        return 0;
    }
    return 0;
}