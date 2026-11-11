#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n,m,ans;
string s;
pair<int,char> a[MAXN];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int tmp_max=-1;
    for(int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        // cout<<a[i].first<<" "<<a[i].second<<"\n";
        tmp_max=max(tmp_max,a[i].first);
        // cout<<s<<"\n";
    }
    // return 0;
    // cout<<s<<"\n";
    // if(tmp_max<1e3){
    //     for(int i=1;i<=n;++i)[
    //         for(int j=1;j<=a[i].first;++j) s+=a[i].second;
    //     ]
    //     m=s.size();
    //     s=' '+s;
    //     for(int i=1;i<=m/2;++i){
    //         // cout<<i<<" "<<s[i]<<" "<<s[m-i+1]<<"\n";
    //         if(s[i]!=s[m-i+1]){
    //             // cout<<i<<"\n";
    //             ans++;
    //         }
    //     }
    //     cout<<ans<<"\n";
    //     return 0;
    // }
    int l=1,r=n;
    while(l<r){
        // cout<<l<<' '<<r<<"\n";
        if(a[l].second==a[r].second){
            if(a[l].first<a[r].first){
                a[r].first-=a[l].first;
                l++;
            }
            else if(a[l].first>a[r].first){
                a[l].first-=a[r].first;
                r--;
            }
            else{
                l++,r--;
            }
        }
        else{
            if(a[l].first<a[r].first){
                // cout<<l<<" "<<r<<"@1\n";
                a[r].first-=a[l].first;
                ans+=a[l].first;
                l++;
            }
            else if(a[l].first>a[r].first){
                // cout<<l<<" "<<r<<"@2\n";
                a[l].first-=a[r].first;
                ans+=a[r].first;
                r--;
            }
            else{
                ans+=a[r].first;
                l++,r--;
            }
        }
        
    }
    cout<<ans<<"\n";
}