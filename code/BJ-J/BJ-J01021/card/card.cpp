#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int t[500010];
int e=0;
int cnt[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(is_sorted(a+1,a+1+n)){
        for(int k=1;k<=n;k++){
            unordered_map<int,int> mp;
            e=0;
            for(int i=k;i<=n;i++){
                //if(a[i]==a[i-1])continue;
                int pos=lower_bound(t+1,t+e+1,a[i])-t;
                if(pos!=e+1)e=pos;
                else t[++e]=a[i];
            }
            for(int i=1;i<=e;i++)cnt[t[i]]++;
    //        for(int i=1;i<=e;i++)cout<<t[i]<<' ';
    //        cout<<endl;
        }
        for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
        return 0;
    }
    for(int k=1;k<=n;k++){
        unordered_map<int,int> mp;
        e=0;
        for(int i=k;i<=n;i++){
            int pos=find(t+1,t+e+1,a[i])-t;
            if(pos!=e+1)e=pos;
            else t[++e]=a[i];
        }
        for(int i=1;i<=e;i++)cnt[t[i]]++;
//        for(int i=1;i<=e;i++)cout<<t[i]<<' ';
//        cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}

