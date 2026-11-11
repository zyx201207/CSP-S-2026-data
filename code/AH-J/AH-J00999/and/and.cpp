#include<bits/stdc++.h>
using namespace std;
const int dd=2e5+5;
int n,m;
int a[dd];
int check(int x,int y){
    stack<int> t;
    while(x!=0){
        t.push(x%2);
        x/=2;
    }
    for(int i=1;i<=t.size();i++){
        cout<<t.top();
        t.pop();
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ans;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,check(a[i],a[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
