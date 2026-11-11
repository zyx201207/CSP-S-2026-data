#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int a[200010],sum[32],bit=29,n,m;
inline bool cmp(int a,int b){
    if(a==b)return false;
    for(int i=bit;i>=0;--i)
        if(sum[i]>=m && a&(1<<i)!=b&(1<<i))
        return a&(1<<i)&&!(b&(1<<i));
    return false;
}
vector<int>Sort(int l,int r){
    if(l==r)return vector<int>({a[l]});
    vector<int>a_=Sort(l,(l+r)>>1),b_=Sort((l+r)>>1+1,r),ret;
    unsigned x,y;x=y=0;
    while(x<a_.size() && y<b_.size()){
        if(cmp(a_[x],b_[y]))ret.push_back(a_[x++]);else ret.push_back(b_[y++]);
    }
    if(x<a_.size())while(x<a_.size())ret.push_back(a_[x++]);
    if(y<b_.size())while(y<b_.size())ret.push_back(b_[y++]);
    return ret;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)for(int j=29;j>=0;--j){
        if(a[i]%(1<<j+1)/(1<<j))++sum[j];
    }
    while(sum[bit]<m && bit>=0)--bit;
    if(bit<0)cout<<'0';
    else{
        int ans=-1;
        vector<int> p=Sort(0,n-1);
        for(int i=0;i<m;++i)ans&=p[i];
        cout<<ans;
    }
    return 0;
}
