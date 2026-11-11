#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    priority_queue<long long,vector<long long>,greater<long long>> as;
    long long a,b,ans;
    cin>>a>>b;
    for (int i=0;i<a;i++){
        long long x;
        cin>>x;
        as.push(x);
        while(as.size()>b){
            as.pop();
        }
    }
    long long e=as.top();
    as.pop();
    long long q=as.top();
    ans=q&e;
    as.pop();
    for (int i=0;i<as.size();i++){
        q=as.top();
        ans=q&ans;
        as.pop();
    }
    cout<<ans;

    return 0;
}
