#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Please return
#define AC 0
int n,m,q[1000000],a[1000000]={0},weizhi[1000000]={0},liupai[1000000]={0},lp[1000000]={0};
bool b[1000000]={0};
/*queuequeuequeuequeuequeuequeue*/
signed main(){
    // Please give me baoli pts
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)cin>>q[i];
    for (int i=0;i<n;i++){
        memset(b,0,sizeof(b));
        memset(weizhi,0,sizeof(weizhi));
        memset(liupai,0,sizeof(liupai));
        int l=0,ad=0;
        for (int j=0;j<n;j++){
            if (!b[q[j]])a[ad]=q[j],b[q[j]]=1,weizhi[q[j]]=ad++;
            else{
                l=weizhi[q[j]]-1;
                ad=l;
                weizhi[q[j]]=ad;
                a[ad++]=q[j];
            }
        }
        for (int j=l;j<n;j++){
            if (b[j])liupai[a[weizhi[j]]]=1;
        }
        for (int j=0;j<m;j++) if(liupai[j]) lp[j]++;
    }
    for (int i=0;i<m;i++) cout<<lp[i]<<' ';
    cout<<endl;
    Please AC;
}
