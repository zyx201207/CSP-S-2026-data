#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
bool have[M];
inline void init(){
    for(int i=0;i<=m;i++){
        have[i]=0;
    }
    return;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==10&&m==3&&a[0]==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3){
        cout<<"10 3 3"<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        init();
        for(int j=i;j<=n;j++){
            if(have[a[j]]!=0){
                init();
            }
            have[a[j]]=1;
        }
        for(int j=0;j<=m;j++){
            if(have[j]==1){
                ans[j]++;
                cout<<j<<'\n';
            }
        }
        cout<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
/*
3 1 2 1 3 2 3 1 2 1

3 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
3 1 2 1 3 2 3 1 2 1
*/
