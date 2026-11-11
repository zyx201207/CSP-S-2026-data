#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct num{
    long long val;
    bool bin[35];
    bool operator <(const num &x)const{
        return val<x.val;
    }
    void getbin(){
        memset(bin,0,sizeof(bin));
        vector<int> ret;
        long long v=val;
        while(v>0){
            long long x=v%2;
            v=v/2;
            ret.push_back(x);
        }
        //reverse(ret.begin(),ret.end());
        for(int i=0;i<ret.size();i++){
            bin[i]=ret[i];
        }
    }
    int getfirst1pos(){
        for(int i=34;i>=0;i--){
            if(bin[i]){
                return i;
            }
        }
        return -1;
    }
}a[MAXN];
int n,m;
vector<num> g[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >>m;
    for(int i=1;i<=n;i++){
        cin >>a[i].val;
        a[i].getbin();
        /*
        cout <<a[i].val <<"\'s binary num=";
        for(int j=34;j>=0;j--) cout <<a[i].bin[j];
        cout <<endl;
        */
    }
    int start=34;
    while(start>=0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i].bin[start]) cnt++;
        }
        if(cnt>=m) break;
        start--;
    }
    if(start<0){
        cout <<0 <<endl;
        return 0;
    }
    //cout <<start <<endl;
    for(int i=1;i<=n;i++) if(a[i].bin[start]) g[start].push_back(a[i]);
    int bax=start;
    for(int i=start-1;i>=0;i--){
        for(num x:g[bax]){
            if(x.bin[i]) g[i].push_back(x);
        }
        if(g[i].size()>=m) bax=i;
    }
    long long ans1=0;
    for(int i=0;i<=34;i++){
        if(g[i].size()>=m){
            long long ans=g[i][0].val;
            for(auto x:g[i]){
                ans&=x.val;
            }
            ans1=max(ans,ans1);
        }
    }
    cout <<ans1 <<endl;
    return 0;
}
