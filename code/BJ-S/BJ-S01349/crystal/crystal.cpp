#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define rf(i,a,b) for(int i=(a);i>=(b);i--)
#define pt printf
#define eb emplace_back
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define FRE(f) {auto u=freopen(f".in","r",stdin);auto v=freopen(f".out","w",stdout);}
#ifdef DBD
void db(){}
void db(auto x,auto...y){cout<<x<<",";db(y...);}
#define Z(x...) {pt("\t%s = ",#x);db(x);pt("\n");}
#define ZZ(x,l,r) {pt("\t%s = ",#x);fr(IT,l,r)cout<<x[IT]<<",";pt("\n");}
#else
#define Z(...)
#define ZZ(...)
#endif
#define int LL
mt19937 gen(random_device{}());
int rnd(int l,int r){return gen()%(r-l+1)+l;}

const int N=1e6+33;
int n,a[N],m;

signed main(){
    FRE("crystal");
    cin>>n>>m;
    fr(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    int j=1,s=0,ans=0;
    fr(i,1,n){
        int k=i-j+1;
        ans=max(ans,k);
        if(i!=n){
            int d=a[i+1]-a[i];
            Z(i,s,k,d);
            s+=k*d;
            // {
            //     int w=0;
            //     fr(t,j,i)w+=a[i+1]-a[t];
            //     Z(i,s,w);   
            //     assert(s==w);
            // }
            while(s>m){
                s-=(a[i+1]-a[j]);
                j++;
            }
            Z(i,j);
        }
    }
    pt("%lld\n",ans);
    return 0;
}