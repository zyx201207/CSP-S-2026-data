#include<bits/stdc++.h>
using namespace std;
int n,mm,ans=1;
vector<int> a;
int craft(int m){
    int k=1,ret=1;
    for(int i=n-2;i>=0;i--){
        if(m>=k*(a[i]-a[i+1])){
            ret++;
            m-=k*(a[i]-a[i+1]);
            k++;
        }else{
            break;
        }
    }
    return ret;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        int p;cin>>p;
        a.push_back(p);
    }
    sort(a.begin(),a.end(),[](int x,int y){return x>y;});
    for(int i=1;i<=n;i++){
        ans=max(ans,craft(mm));
        a.pop_back();
    }
    cout<<ans;
    return 0;
}
