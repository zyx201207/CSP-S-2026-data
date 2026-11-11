#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],k[N],cnt[N],f[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flag=0;
    }
    if(flag){
        for(int i=1;i<=n;i++){
            if(a[i+1]!=a[i]){
                cout<<i<<' ';
            }
        }
        return 0;
    }
    for(int i=n;i>=1;i--){
        int tail=1,_tail=-1;
        for(int i=1;i<=m;i++){
            f[i]=0;
        }
        for(int j=i;j<=n;j++){
//            for(int l=1;l<tail;l++){
//                if(k[l]==a[j]){
//                    tail=l;
//                    break;
//                }
//            }
//            k[tail++]=a[j];
            if(f[a[j]]==0/*||f[a[j]]>_tail*/){
                f[a[j]]=tail;
                k[tail++]=a[j];
            }else{
                tail=f[a[j]]+1;
                //_tail=tail;
                for(int l=1;l<=m;l++){
                    if(f[l]>=tail){
                        f[l]=0;
                    }
                }
            }
        }
        for(int j=1;j<tail;j++){
            cnt[k[j]]++;
            //cout<<k[j]<<' ';
        }
        //cout<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
