#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    int n;
    int m;
    int d;
    int q;
    int r;
    int ai;
    int ti;
    int xr;
    int yr;
    int w;
    int cnt=0;
    int temp[1000000];
    int cnt[1000000];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w>>ai>>ti;
        temp[i]=w;
        cnt[i]=ti;
    }
    cnt+=temp[i]+=cnt[i];
    for(int j=1;j<=n;j++){
        temp[j]=w;
        cnt[j]=ti;
    }
    cnt+=temp[j]+=ti;
    cin>>xr>>yr;
    cnt+=xr+=yr;
    for(int a=0;a<=q;a++){
        for(int q=1;q<=r,q++){
            cout<<cnt<<endl;
        }
    }
    return 0;
}