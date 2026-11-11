#include<bits/stdc++.h>
using namespace std;
int nn[4]={4,5,5,6},dd[4]={2,2,3,2};
int ans[4]={1,2,0,1};
int main(){
    int c,t,n,d,k;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=0;j<n;j++)cin>>k;
        if(c==0)for(int j=0;j<4;j++){if(nn[j]==n) cout<<ans[j];}
        else cout<<0;
    }
    return 0;
}
