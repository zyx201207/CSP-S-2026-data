#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
struct Char{
    ll from,len;char c;
    Char(int f,int l,char c_){from=f;len=l;c=c_;}
    Char(){from=len=c=0;}
};
vector<Char>vec;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,sum=0;cin>>n;
    for(ll i=0;i<n;++i){
        int a;char c;cin>>a>>c;
        vec.push_back(Char(sum,a,c));
        sum+=a;
    }ll l=0,r=n-1,ans=0;
    while(l<r){
                if(vec[l].len>vec[r].len){ans+=vec[r].len*(vec[l].c!=vec[r].c);vec[l].len-=vec[r].len;--r;}
        else    if(vec[l].len<vec[r].len){ans+=vec[l].len*(vec[l].c!=vec[r].c);vec[r].len-=vec[l].len;++l;}
        else                             {ans+=vec[l].len*(vec[l].c!=vec[r].c);--r;++l;}
    }cout<<ans<<endl;
    return 0;
}
