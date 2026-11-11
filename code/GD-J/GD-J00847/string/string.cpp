#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n;
struct Node{
    int len;
    char c;
}a[maxn];
vector<Node>L,R;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        l+=a[i].len;
    }
    int mid=(l+1)>>1,now=0,lst=0;
    bool flag=0;
    for(int i=1;i<=n;i++){
        now+=a[i].len;
        if(now>=mid&&!flag){
            if(l&1){
                if(mid-lst-1>0)L.push_back({mid-lst-1,a[i].c});
                if(now-mid>0)R.push_back({now-mid,a[i].c});
            }
            else{
                L.push_back({mid-lst,a[i].c});
                if(now-mid>0)R.push_back({now-mid,a[i].c});
            }
            flag=1;
        }
        else if(!flag)L.push_back({a[i].len,a[i].c});
        else R.push_back({a[i].len,a[i].c});
        lst=now;
    }
    int ans=0,id=0,id1=(int)R.size()-1;
    while(id<(int)L.size()&&id1>=0){
        int tmp=min(L[id].len,R[id1].len);
        if(L[id].c!=R[id1].c)ans+=tmp;
        L[id].len-=tmp,R[id1].len-=tmp;
        if(!L[id].len)id++;
        if(!R[id1].len)id1--;
    }
    cout<<ans;
    return 0;
}
