#include <bits/stdc++.h>

using namespace std;
struct node{
    int num;
    char letter;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<node> v;
    v.reserve(n+10);
    v.push_back({0,'q'});
    int m;char c;
    for(int i=0;i<n;i++){
        cin>>m>>c;
        v.push_back({m,c});
    }
    int s=1;
    int e=v.size()-1;
    long long ans=0;
    while(s<e){
        int d=min(v[s].num,v[e].num);
        if(v[s].letter!=v[e].letter){
            ans+=d;
        }
        v[s].num-=d;
        v[e].num-=d;
        if(v[s].num==0)s++;
        if(v[e].num==0)e--;
    }
    cout<<ans;
}
