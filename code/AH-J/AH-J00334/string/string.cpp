#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
struct block{
    long long length;
    char c;
};
void cutdown(vector<block>& s,int bcnt,long long pos,bool mode){
    if (bcnt>=s.size()) return;
    if (pos>=s[bcnt].length) return ;
    long long ls=s[bcnt].length;
    char cc=s[bcnt].c;
    if (mode){
        int p=1;
        s[bcnt].length=1;
        if (pos!=0) {s.insert(s.begin()+bcnt,{pos,cc});p++;}
        if ((ls-pos-1)!=0) s.insert(s.begin()+bcnt+p,{ls-pos-1,cc});
    }else{
        s[bcnt].length=pos+1;
        if ((ls-pos-1)!=0) s.insert(s.begin()+bcnt+1,{ls-pos-1,cc});
    }
}
long long arr[MAXN];
long long ads[MAXN];
vector<block> s;
long long n,w,lp,rp,rmiu,l,mid,ans;
char in;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];cin>>in;
        s.push_back({arr[i],in});
        ads[i+1]=arr[i]+ads[i];
    }
    l=ads[n];
    mid=(l-1)/2;
    w=upper_bound(ads,ads+n,mid)-ads;
    //block:{w-1,mid-ads[w-1]}
    cutdown(s,w-1,mid-ads[w-1],(l&1));
    lp=0;rp=s.size()-1;rmiu=0;
    while(lp<rp){
        if (s[lp].length < (s[rp].length-rmiu)){
            rmiu+=s[lp].length;
            if(s[lp].c!=s[rp].c) ans+=s[lp].length;
        }else if(s[lp].length==(s[rp].length-rmiu)){
            rmiu=0;
            if(s[lp].c!=s[rp].c)ans+=s[lp].length;
            rp--;
        }else{
            rmiu+=s[lp].length;
            while (rmiu>=s[rp].length&&(lp<rp)){
                if(s[lp].c!=s[rp].c) ans+=s[rp].length;
                rmiu-=s[rp].length;
                rp--;
            }
            if (s[lp].c!=s[rp].c) ans+=rmiu;
        }
        lp++;
    };
    cout<<ans<<endl;
    return 0;
}
