#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6;
int c,n,m,d,q,k1,x,y,ans;
int w[N],k[N],s[N];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >>m >> d >> q;

    for(int i=1;i<=m;i++){
        cin >> w[i];
    }

    for(int i=1;i<=n;i++){
        cin >> k1;

        for(int j=1;j<=k1*2;j++){
            cin >> k[i];
            s[i]=k[i];

        }
        ans+=s[x];
        if(i%2!=0 && k[i]==x+1)
        {
            ans+=s[x+1];
        }else{
            ans+=k[x+1];
        }
        if(i%2!=0 && k[i]==x+2)
        {
            ans+=(s[x+3]+k[y-1]);
        }else{
            ans+=(k[x+3]+k[y-1]);
        }


    }
    for(int i=1;i<=q;i++){
        cin >> x >> y;
    }
    ans+=(w[x]+w[y]);

    return 0;
}

