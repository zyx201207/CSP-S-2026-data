#include <bits/stdc++.h>
using namespace std;
struct node{
    long long cnt;
    char c;
}a[200010];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt>>a[i].c;
    }
    long long ans=0;
    stack<node> s1,s2;
    int l=1,r=n;
    while(l<=r){
        if(s1.empty())s1.push(a[l++]);
        if(s2.empty())s2.push(a[r--]);
        node u=s1.top(),v=s2.top();
        s1.pop();s2.pop();
        if(u.c!=v.c)ans+=min(u.cnt,v.cnt);
        if(u.cnt==v.cnt)continue;
        if(u.cnt>v.cnt)s1.push({u.cnt-v.cnt,u.c});
        else s2.push({v.cnt-u.cnt,v.c});
    }
    cout<<ans<<endl;
    return 0;
}
