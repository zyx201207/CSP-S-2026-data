#include <bits/stdc++.h>
using namespace std;
struct node{
    long long l,r;
    char ch;
};
int l[200005];
char ch[200005];
vector<node> vl,vr;
int main(){
    ios::sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long len=0;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>ch[i];
        len+=l[i];
    }
    long long lf=0,rt=0;
    int lid=1,rid=n;
    while(lf+l[lid]<len/2+1){
        vl.push_back({lf+1,lf+l[lid],ch[lid]});
        lf+=l[lid];
        lid++;
    }
    if(lf<len/2){
        vl.push_back({lf+1,len/2,ch[lid]});
    }
    while(rt+l[rid]<len/2+1){
        vr.push_back({rt+1,rt+l[rid],ch[rid]});
        rt+=l[rid];
        rid--;
    }
    if(rt<len/2){
        vr.push_back({rt+1,len/2,ch[rid]});
    }
    // for(auto i:vl){
    //     cout<<i.l<<"-"<<i.r<<":  "<<i.ch<<'\n';
    // }
    // cout<<"//\n";
    // for(auto i:vr){
    //     cout<<i.l<<"-"<<i.r<<":  "<<i.ch<<'\n';
    // }
    // return 0;
    rid=-1;
    long long ans=0,lst=0;
    for(auto i:vl){
        while(rid+1<vr.size()&&vr[rid+1].r<=i.r){
            rid++;
            if(vr[rid].ch!=i.ch){
                ans+=vr[rid].r-lst;
            }
            lst=vr[rid].r;
        }
        if(rid==-1||vr[rid].r<i.r){
            if(vr[rid+1].ch!=i.ch){
                ans+=i.r-lst;
            }
            lst=i.r;
        }
    }
    cout<<ans;
    return 0;
}