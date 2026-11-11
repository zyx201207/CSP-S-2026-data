#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
#define FOR(i,a,b) for(int i=(a),EEEE##i=(b); i<=EEEE##i; i++)
#define REV(i,a,b) for(int i=(a),EEEE##i=(b); i>=EEEE##i; i--)
#define endl '\n'
template<typename T>
void outval_(string s,int p,const T& t){cerr<<s.substr(p,s.size()-p)<<"="<<t<<endl;}
template<typename T,typename... Args>
void outval_(string s,int p,const T& t,const Args& ...rest){
    while(s[p]!=',') cerr<<s[p++]; cerr<<"="<<t<<"  ";
    outval_(s,p+1,rest...);}
#define outval(...) outval_(#__VA_ARGS__,0,__VA_ARGS__)
#define outarr(aaa,beee,eddd)\
{cerr<<(#aaa)<<": "; FOR(iii,beee,eddd) cerr<<'['<<iii<<']'<<'='<<aaa[iii]<<"  "; cerr<<endl;}
bool MBE;
const int N=5e5+5;
ll n,m,a[N];
i128 sum[N];
int ans;
bool MED;
int main(){
//    freopen("/home/csp-s-2026/crystal/crystal4.in","r",stdin);
//    freopen("in.txt","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll mx=0;
    FOR(i,1,n) cin>>a[i],mx=max(mx,abs(a[i]));
//    outval(n,m,mx);
    sort(a+1,a+n+1);
    FOR(i,1,n) sum[i]=sum[i-1]+(i128)a[i];
    FOR(i,1,n){
        auto bin=[&](){
            int l=0,r=i,res=-1;
            while(l<=r){
                int mid=(l+r)>>1;
                i128 x=(i128)a[i]*(i-mid)-sum[i]+sum[mid];
                if(x<=(i128)m) res=mid,r=mid-1;
                else l=mid+1;
            }
            return res;
        };
        int res=bin();
//        assert(res!=-1);
//        outval(i,res);
        ans=max(ans,i-res);
    }
    cout<<ans<<endl;
    cerr<<fixed<<setprecision(3)<<abs(&MBE-&MED)/1048576.0<<" MB"<<endl;
    return 0;
}
//Think twice, code once!!!
//luogu uid=923403, RP++
//Oct31==Dec25?
