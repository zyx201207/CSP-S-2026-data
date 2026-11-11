#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
long long n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long ans=0;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++){
        long long idx=m-1,maxx=a[i];
        for(int j=i+1;j<=n;j++){
            if(idx!=0){
                maxx&=a[j];
                idx--;
            }else break;
        }
        if(idx==0)ans=max(ans,maxx);
    }
    cout<<ans<<"\n";
    return 0;
}
