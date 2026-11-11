#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],mp[200010];
long long t[200010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(j!=mp[a[j]])j=mp[a[j]];
            else {
                t[a[j]]++,j++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
