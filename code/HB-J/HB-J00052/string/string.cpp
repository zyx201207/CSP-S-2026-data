#include <bits/stdc++.h>

using namespace std;
pair<int,char>hui[20002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    //cout<<n;
    for(int i=1;i<=n;i++){
           int k; cin>>k;
        hui[i].first=k;
        //cin>>hui[i].first;
        cin>>hui[i].second;
    }
    int l=1,r=n;
    int sum=0;
    while(l<=r){
        if(hui[l].second!=hui[r].second){
            int k=min(hui[l].first,hui[r].first);
            sum+=k;
            hui[l].first-=k;
            hui[r].first-=k;
        }
        if(hui[l].first==0)
        l++;
        if(hui[r].first==0)
        r--;
    }
    cout<<sum;
    return 0;
}
