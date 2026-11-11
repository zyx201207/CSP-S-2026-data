#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in",'r',stdin);
    freopen("crystal.out",'w',stdout);
    int n,m,ans,times;
    ans=0;
    cin>>n>>m;
    times = m;
    int a[n];
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    if(times==0){
        for(int j=0;j<=n;j++){
            if(a[j]==a[j+1]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
 }
