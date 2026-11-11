#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxx=-1000000,ans=a[0];
    if(m==1){
        for(int i=0;i<n;i++){
            maxx=max(a[i],maxx);
        }
        cout<<maxx;
    }else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                maxx=max(a[i]&a[j],maxx);
            }
        }
        cout<<maxx;
    }else if(m==n){
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }else{
        sort(a.begin(),a.end());
        ans=a[0];
        for(int i=1;i<m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    return 0;
}
