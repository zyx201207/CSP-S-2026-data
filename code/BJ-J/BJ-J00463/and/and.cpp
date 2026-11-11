#include <bits/stdc++.h>
using namespace std;
int a[200005];
int k;

bool cmp(const int a,const int b){
    return (a>>k)%2 > (b>>k)%2;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    k=(int)log2(maxn);
    int t=n;
    while(k>=0){
        //cout<<k<<" "<<t<<endl;
        sort(a+1,a+t+1,cmp);
        //for(int i=1;i<=t;i++){
            //for(int ttt=(int)log2(a[i]);ttt>=0;ttt--){
                //cout<<(a[i]>>ttt)%2;
            //}
            //cout<<endl;
        //}
        int tmp=1;
        while((a[tmp]>>k)%2 && tmp<=t) tmp++;
        tmp--;
        k--;
        if(tmp<m) continue;
        //ans+=(2<<k);
        t=tmp;
    }
    int ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
