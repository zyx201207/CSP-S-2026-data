#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int lowbit(int x){
    return x&-x;
}
bool cmp(pair<int,int> a,pair<int,int>b){
    if(a.second==b.second) return a.first>b.first;
    else return a.second>b.second;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    pair<int,int> a[N];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i].first=x;
        while(x){
            x-=lowbit(x);
            a[i].second++;
        }
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1].first;
    for(int i=1;i<=m;i++){
        ans&=a[i].first;
    }
    cout<<ans;
    return 0;
}
