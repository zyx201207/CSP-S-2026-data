#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],cnt[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++){
        set<int> st;
        int lp=i,sz=0;
        for(int j=i;j<=n;j++){
            sz=st.size();
            st.insert(a[j]);
            if(sz==st.size()){
                lp=j;
                st.clear();
                sz=0;
            }
        }
        for(int j=lp;j<=n;j++) cnt[a[j]]++;
    }
    for(int j=1;j<=m;j++) printf("%d ",cnt[j]);
    return 0;
}
