#include<bits/stdc++.h>
#define int long long
using namespace std;
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
int a[200010],reva[200010];
vector<int>b,revb;
vector<char>d,revd;
char c[200010],revc[200010];
void solve(){
    int n,ans=0;
    cin>>n;
    cin>>a[0]>>c[0];
    for(int i=1;i<n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    for(int i=0;i<n;i++){
        reva[n-i-1]=a[i];
        revc[n-i-1]=c[i];
    }
    int posa=0,posra=0;
    while(posa<n||posra<n){
        int t=min(a[posa],reva[posra]);
        b.pb(t);
        revb.pb(t);
        d.pb(c[posa]);
        revd.pb(revc[posra]);
        if(a[posa]==reva[posra]){
            posa++;
            posra++;
        }
        else if(a[posa]==t){
            posa++;
            reva[posra]-=t;
        }
        else{
            posra++;
            a[posa]-=t;
        }
    }
    int m=b.size();
    //for(int i=0;i<m;i++){
    //    cout<<b[i]<<' '<<d[i]<<endl;
    //}
    //cout<<endl;
    //for(int i=0;i<m;i++){
    //    cout<<revb[i]<<' '<<revd[i]<<endl;
    //}
    for(int i=0;i<m/2;i++){
        if(d[i]!=revd[i]){
            ans+=b[i];
        }
    }
    cout<<ans;

}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    //freopen("string6.in","r",stdin);
    //freopen("string.out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)solve();
}
/*
容易证明其正确性，回文中心一定相同无需特判一定可以/2出
也可以不用/2，搜半程然后输出
科研成功！

这个应该是必须longlong吧
开了不要炸求求了
测试数据变waterful谢谢喵
样例给的不waterful谢谢喵
*/
