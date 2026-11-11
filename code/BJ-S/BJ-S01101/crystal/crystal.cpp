#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("crystal.in";"r";stdin);
    //freopen("crystal.out";"w";stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=1;
    sort(a+1,a+n+2);
    for(int i=2;i<=n;i++){
        int max=1;
        int sum=0;
        for(int j=i-1;j>0;j--){
            sum+=a[i]-a[j];
            if(sum>m){
                break;
            }
            max++
        }
        if(max>ans){
            ans=max;
        }
    }
    cout<<ans;
    return 0;
}