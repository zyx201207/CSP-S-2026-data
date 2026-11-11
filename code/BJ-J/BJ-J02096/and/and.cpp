#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],s[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]&a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(m==1){
        cout<<s[1];
        return 0;
    }
    else if(m==n){
        cout<<s[n];
        return 0;
    }
    else if(m==2){
        int ans=0;
        for(int i=1;i<=n-1;i++){
            ans=max(ans,a[i]&a[i+1]);
        }cout<<ans;
        return 0;
    }else{
        int q=a[1];
        for(int i=2;i<=m;i++){
            q=q&a[i];
        }cout<<q;
    }
    return 0;
}
