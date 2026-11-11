#include<iostream>
using namespace std;

const int MAXN=2e5+5,MAXL=30;
int n,m,a[MAXN],c[MAXN][MAXL];
bool flag[MAXN];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int pos=0,t=a[i];
        while(t>0)c[i][pos++]=t%2,t/=2;
    }
    int ans=0;
    for(int i=1;i<=n;i++)flag[i]=true;
    for(int j=29;j>=0;j--){
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=flag[i]*c[i][j];
        if(cnt<m)continue;
        ans+=(1<<j);
        for(int i=1;i<=n;i++)
            if(!c[i][j])flag[i]=false;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=4;j>=0;j--)cout<<c[i][j];
    //     cout<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}