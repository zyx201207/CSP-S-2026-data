#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),s(m+1);
    for(int aa=1;aa<=n;aa++)cin>>a[aa];
    for(int i=1;i<=n;i++){
        vector<int> aa(n+1),sa(n+2,-1);
        int ss=0;
        for(int ii=i;ii<=n;ii++){
            aa[ii]++;
            sa[ss]=ii;
            ss++;
            if(aa[ii]>1){
                sa[ss-1]=-1;
                aa[ii]-=1;
                while(sa[ss]!=ii){
                        aa[sa[ss]]--;
                    sa[ss]=-1;
                    ss--;
                }
                sa[ss]=-1;
            }
        }
        for(int aaa=0;aaa<=ss;aaa++){
            if(sa[aaa]!=-1)s[sa[aaa]]++;
        }
    }
    for(int dd=1;dd<=m;dd++)cout<<s[dd]<<" ";
    return 0;
}