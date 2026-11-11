#include <bits/stdc++.h>
using namespace std;
struct node{
    int cnt;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    vector<node> v(n+1);
    for (int i=1;i<=n;i++){
        cin>>v[i].cnt>>v[i].c;
    }
    int l=1,r=n;
    long long ans=0;
    while (l<r){
        if (v[l].cnt>v[r].cnt){
            v[l].cnt-=v[r].cnt;
            if (v[l].c!=v[r].c) ans+=v[r].cnt;
            v[r].cnt=0;
            r--;
        }
        else{
            v[r].cnt-=v[l].cnt;
            if (v[l].c!=v[r].c) ans+=v[l].cnt;
            v[l].cnt=0;
            l++;
        }
    }
    cout<<ans;
    return 0;
}