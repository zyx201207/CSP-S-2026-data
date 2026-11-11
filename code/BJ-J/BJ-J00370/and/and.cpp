#include <bits/stdc++.h>
using namespace std;
int a[200001],n,m;
bool cmp(int x,int y){
    return x>y;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int cnt=a[1];
        for(int i=2;i<=n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
    }else if(m==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
    }else if(m==2){
        int t=1;
        int s[2000001]={0};
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                s[t++]=a[i]&a[j];
            }
        }
        sort(s+1,s+t+1,cmp);
        cout<<s[1];
    }else{
        sort(a+1,a+n+1,cmp);
        int ans=a[1];
        for(int i=2;i<=m;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}
