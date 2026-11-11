#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+5;

int n; ll m;
ll a[maxn];
int ans=0;
int up[maxn];
int now_[maxn];
int energy[maxn];

bool cmp(const ll &x, const ll &y){return x<y;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+n+1, cmp);
    for(int i=1;i<=n;i++) up[i]=1, now_[i]=i, energy[i]=m;

    bool spec = true; ll check = a[n]-a[n-1];
    for(int i=n;i>=2;i--){
        if(a[i]-a[i-1]!=check){spec=false; break;}
    }
    if(spec){
        int cnt=0; ll brute=0;
        for(int i=1;i<=n;i++){
            brute += (i*check);
            if(brute<=m) cnt++;
            else break;
        }
        cout<<cnt+1<<"\n";
        return 0;
    }


    for(int i=1;i<=n;i++){
        int cnt = up[i];
        for(int j = now_[i]-1; j>=1;j--){
            if(a[i]-a[j]<=energy[i]){
                cnt++;
                energy[i]-=(a[i]-a[j]);
                if(energy[i+1]>=(a[i+1]-a[i])){
                    up[i]++;
                    energy[i+1]-=a[i+1]-a[i];
                    now_[i+1]=j;
                }
            } else break;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<"\n";
    return 0;


}
