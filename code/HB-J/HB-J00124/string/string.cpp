#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;

int maxa=-1e18,n,a[N],ans,pre[N],suf[N];
char c[N];

namespace subtask1{
    string s="";
    void solve(){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=a[i];j++)
                s.push_back(c[i]);

        int len=s.size();
        int ans=0,mid=len/2,l=mid,r=mid;
        if(len%2==0) r+=1;
        while(l>=0 && r<(int)s.size()){
            if(s[l]!=s[r])
                ans++;
            l--,r++;
        }
        cout << ans << '\n';
    }
}

namespace subtask2{
    string s="";
    void solve(){
        int len=0;
        vector<int> a1,a2,w;
        vector<char> c1,c2;
        
        int l=1,r=n;
        while(l<=r){
            if(a[l]==a[r]){
                a1.push_back(1);
                a2.push_back(1);
                c1.push_back(c[l]-32);
                c2.push_back(c[r]-32);
                w.push_back(a[l]);
            }else if(a[l]>a[r]){
                a1.push_back(1);
                a2.push_back(1);
                w.push_back(a[r]);
                c1.push_back(c[l]-32);
                c2.push_back(c[r]-32);
                a1.push_back(a[l]-a[r]);
                c1.push_back(c[l]);
            }else if(a[l]<a[r]){
                a1.push_back(1);
                a2.push_back(1);
                c1.push_back(c[l]-32);
                c2.push_back(c[r]-32);
                w.push_back(a[l]);
                a2.push_back(a[r]-a[l]);
                c2.push_back(c[r]);
            }
            l++,r--;
        }

        for(int i=0;i<(int)a1.size();i++)
            for(int j=1;j<=a1[i];j++)
                s.push_back(c1[i]);

        for(int i=(int)a2.size()-1;i>=0;i--)
            for(int j=1;j<=a2[i];j++)
                s.push_back(c2[i]);

        int cnt=0;
        l=0,r=s.size()-1;
        while(l<=r){
            if('A'<=s[l] && 'Z'<=s[l] && 'A'<=s[r] && 'Z'<=s[r]){
                ans+=w[cnt];
                cnt++;
            }
            l++,r--;
        }
        cout << ans << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> c[i],maxa=max(a[i],maxa);

    if(maxa<=500){
        subtask1::solve();
    }else{
        subtask2::solve();
    }
    return 0;
}
//g++ -o string string.cpp -O2 -std=c++14 -static