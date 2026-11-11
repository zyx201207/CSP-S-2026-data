#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2e5+10;
const int maxm=3e1+10;
int n,m,k,ans,hi,a[maxn],cnt[maxm],pow2[maxm];
set<int> se[maxm],ansse;
int getmax(int x){
    ll tmp=1;
    for (int i=0;;i++){
        if (tmp>x) return i-1;
        tmp*=2;
    }
}
set<int> cnt2(set<int> b,set<int> c){
    set<int> d;
    for (int i=1;i<=n;i++)
        if (b.count(a[i])&&c.count(a[i]))
            d.insert(a[i]);
    return d;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    pow2[0]=1;
    for (int i=1;i<=30;i++)
        pow2[i]=pow2[i-1]*2;
    cin>>n>>m;
    //cout << m << '\n';
    for (int i=1;i<=n;i++){
        cin>>a[i];
        hi=max(hi,getmax(a[i]));
    }
    sort(a+1,a+n+1);
    for (int i=hi;i>=0;i--)
        for (int j=1;j<=n;j++)
            if (a[j]&pow2[i]){
                cnt[i]++;
                se[i].insert(a[j]);
            }
    bool flag=true;
    for (int i=hi;i>=0;i--)
        if (cnt[i]>=m){
            set<int> tmp=cnt2(ansse,se[i]);
            if (flag){
                ans+=pow2[i];
                ansse=se[i];
            }
            else if (tmp.size()>=m){
                ans+=pow2[i];
                ansse=tmp;
            }
            flag=false;
        }
    vector<int> ansve;
    for (int i=1;i<=n;i++)
        if (ansse.count(a[i]))
            ansve.push_back(a[i]);
    sort(ansve.begin(),ansve.end());
    //for (int i=0;i<ansve.size();i++)
    //    cout << ansve[i] << " ";
    int tmpcnt=1;
    for (int i=ansve.size()-1;i>=1;i--){
        if (ansve[i]==ansve[i-1])
            tmpcnt++;
        else {
            //cout << tmpcnt << '\n';
            if (tmpcnt>=m){
                cout << ansve[i] << '\n';
                return 0;
            }
            tmpcnt=1;
        }
    }
    cout << ans << '\n';
    return 0;
}
