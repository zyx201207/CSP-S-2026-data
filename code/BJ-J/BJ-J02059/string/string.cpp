#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
int n;
pair<int,char> in[MAXN],re[MAXN];
int ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int maxsize=0;
    for(int i=1;i<=n;i++){
        int a;char c;
        cin>>a>>c;
        in[i].first=a,in[i].second=c;
        maxsize+=a;
    }
    for(int i=1;i<=n;i++){
        re[i].first=in[n+1-i].first;
        re[i].second=in[n+1-i].second;
    }
    int len=0,l=1,r=1,rel=0,rer=0;
    while(len<(maxsize>>1)){
        char cl=in[l].second,cr=re[r].second;
        int al=(rel!=0)?rel:in[l].first,ar=(rer!=0)?rer:re[r].first;
        if(cl==cr){
            len+=min(al,ar);
            if(al<ar) rer=ar-al,rel=0,l++;
            else if(ar<al) rel=al-ar,rer=0,r++;
            else rel=0,rer=0,l++,r++;
        }
        else{
            len+=min(al,ar);ans+=min(al,ar);
            if(al<ar) rer=ar-al,rel=0,l++;
            else if(ar<al) rel=al-ar,rer=0,r++;
            else rel=0,rer=0,l++,r++;
        }
    }
    cout<<ans;
    return 0;
}
