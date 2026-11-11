#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],t[N],s[N];
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=1;
    }
    int l=n+1,r=n+1;
    for(int i=n;i>=1;i--){
        if(t[a[i]]==0||l<=t[a[i]]&&t[a[i]]<=r){
            t[a[i]]=i;
        }else{
            l=i-i;
            r=t[a[i]];
            s[l]--;
            s[r+1]++;
            t[a[i]]=i;
        }
    }
    //for(int i=1;i<=n;i++){
      //  cout<<s[i]<<" ";
    //}
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+s[i];
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=s[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
