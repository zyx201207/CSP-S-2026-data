#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long ans=0;
    for(int i=0;i<n;i++){
       int x=0;
       if(n%2==1){
          x=a[n/2+1];
       }
       while(m--){
         if(a[i]<x) a[i]++;
         else if(a[i]==x||a[i]>x) continue;
       }
    }

    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]) ans++;
    }
    cout<<ans;

    return 0;
}
