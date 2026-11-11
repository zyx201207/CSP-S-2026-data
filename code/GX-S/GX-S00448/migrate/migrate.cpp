#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    cin>>c>>t;
    while(t--){
        int n=0,d=0;
        cin>>n>>d;
        int x[2000010]={0},dx[2000010]={0};
        for(int i=1;i<=n;i++)cin>>x[i],dx[i]=x[i]-x[i-1];
        int res=0;
        for(int i=1;i<=n;i++){
            if(dx[i]>d)continue;
            else {}
        }
        cout<<res;
    }
    return 0;
}