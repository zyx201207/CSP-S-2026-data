#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+10;
int n,m,a[N];
int s[N];
int find(int n,int c){
    bool b=0;
    int i;
    for(i=1;i<=n;i++){
        if(s[i]==c){
            b=1;
            break;
        }
    }
    if(b)return i;
    return -1;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    s[0]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans[N];
    for(int i=1;i<=n;i++){
        int len=0;
        for(int j=i;j<=n;j++){
            int x=find(len,a[j]);
            if(x!=-1){
                int le=0;
                for(int i=x;i<=len;i++){
                    s[i]=-1;
                    le++;
                }
                len-=le;
            }
            s[++len]=a[j];
        }
        for(int i=1;i<=len;i++)ans[s[i]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
