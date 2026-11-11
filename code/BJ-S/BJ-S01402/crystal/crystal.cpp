#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=-1;
void func(int x){
    vector<long long> v;
    long long cnt=0;
    for(int i=x;i>=1;i--){
        if(a[x]>a[i]) v.push_back(a[x]-a[i]);
        if(a[i]==a[x]) cnt++;
    }
    long long sum=0;
    for(auto g:v){
        sum+=g;
        if(sum<=m) cnt++;
        else break;
    }
    ans=max(ans,cnt);
}
void solvea(){
    long long sum=1;
    for(int i=2;i<=n;i++){
        sum+=i;
        if(sum>m){
            cout<<i;
            return;
        }
    }
}
void solveb(){
    long long sum=a[1];
    for(int i=2;i<=n;i++){
        sum+=a[i];
        if(sum>m){
            cout<<i;
            return;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flaga=true,flagb=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) flaga=false;
    }
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[2]-a[1]){
            flagb=false;
            break;
        }
    }
    if(flaga){
        solvea();
        return 0;
    }
    if(flagb){
        solveb();
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) func(i);
    cout<<ans;
    return 0;
}
