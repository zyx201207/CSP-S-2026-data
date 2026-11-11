#include<bits/stdc++.h>
using namespace std;
pair<int,char>a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=0,b;
    long long cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    b=n-1;
    if(n==1){
        cout<<0;
        return 0;
    }
    while(b-c>0){
        if(a[c].second!=a[b].second){
                cnt+=min(a[c].first,a[b].first);
        }
        int t=min(a[c].first,a[b].first);
        a[c].first-=t;a[b].first-=t;
        if(a[c].first==0)c++;
        if(a[b].first==0)b--;
    }
    cout<<cnt;
    return 0;
}
