#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int num[M],arr01[N],arr02[N];
bool s(int cnt,int key){
    for(int i=0;i<cnt;++i)
        if(arr02[i]==key)
            return i;
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>arr01[i];
    for(int i=1;i<=n;++i){
        int cnt=1;
        for(int j=i;j<=n;++j){
            int k=s(cnt,arr01[j]);
            if(k){
                for(int i=k+1;i<cnt;++i)
                    arr02[i]=0;
                cnt=k+1;
            }
            else
                arr02[cnt++]=arr01[j];
        }
        sort(arr02+1,arr02+cnt);
        for(int j=1;j<cnt;++j)
            num[arr02[j]]++;
        memset(arr02,sizeof arr02,0);
    }
    for(int i=1;i<=m;++i)
        cout<<num[i]<<' ';
    cout<<'\n';
    return 0;
}
