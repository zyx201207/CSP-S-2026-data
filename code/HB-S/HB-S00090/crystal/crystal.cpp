#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;

int n,m,a[N],d[N],ans=0,flag1=1,flag2=1,pre[N],maxn=-1e18,minn=1e18;

vector<int> dis;

namespace subtask1{
    void solve(){
        sort(a+1,a+1+n);

        for(int i=1;i<=n;i++){
            int cnt=1,tmp=m;
            for(int j=i-1;j>=1;j--){
                int delta=a[i]-a[j];
                if(tmp>=delta) tmp-=delta,cnt++;
                else break;
            }
            ans=max(ans,cnt);
        }
        cout << ans << '\n';
    }
}

namespace subtask2{
    void solve(){
        for(int i=2;i<=n;i++) pre[i]=pre[i-1]+i-1;
        for(int i=n;i>=1;i--){
            if(pre[i]<=m){
                cout << i << '\n';
                break;
            }
        }
    }
}

namespace subtask3{
    void solve(){
        for(int i=2;i<=n;i++) pre[i]=pre[i-1]+(a[n]-a[n-i+1]);
        for(int i=n;i>=1;i--){
            if(pre[i]<=m){
                cout << i << '\n';
                break;
            }
        }
    }
}

namespace subtask4{
    int binary_search(int x){
        int pos=-1,L=1,R=n;
        while(L<=R){
            int mid=(L+R)>>1;
            if(a[mid]<=x) pos=mid,L=mid+1;
            else R=mid-1;
        }
        return pos;
    }

    void solve(){
        sort(a+1,a+1+n);

        for(int k=minn;k<=maxn;k++){
            int pos=binary_search(k);
            if(pos==-1) continue;

            int delta=k-a[pos],tmp=m,cnt=0;
            for(int i=pos;i>=1;i--){
                int x=k-a[i];
                if(tmp>=x) tmp-=x,cnt++;
                else break;
            }
            ans=max(ans,cnt);
        }
        cout << ans << '\n';
    }
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
        if(a[i]!=i) flag1=0;
    }

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
        if(d[i]!=1) flag2=0;
    }

    if(n<=5000){
        subtask1::solve();
    }else if(flag1){
        subtask2::solve();
    }else if(flag2){
        subtask3::solve();
    }else{
        subtask4::solve();
    }
    return 0;
}
//g++ -o crystal crystal.cpp -O2 -std=c++14 -static