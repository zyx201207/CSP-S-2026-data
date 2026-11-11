#include <bits/stdc++.h>

using namespace std;
#define vec vector
#define For(n) for(int i=0;i<n;++i)

int main(){
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto f1 = freopen("crystal.in","r",stdin);
    auto f2 = freopen("crystal.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vec<int> a(n);
    For(n) {
        cin>>a[i];
    };

    sort(a.begin(),a.end());

    vec<int> diff(n-1);
    For(n-1) diff[i]=(a[i+1]-a[i])*(i+1);
    vec<int> sum(n);
    sum[0]=0;
    for(int i=1;i<n;++i){
        sum[i]=sum[i-1]+diff[i-1];
    }

    int result=1;

    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int d = sum[j]-sum[i];
            if(d>m){
                result=max(result,j-i+1);
                break;
            }
        }
    }

    cout<<result-1<<endl;
    #undef int
}