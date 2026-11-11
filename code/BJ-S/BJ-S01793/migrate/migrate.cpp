#include<bits/stdc++.h>
using namespace std;

int c,t;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        int n,d,cnt=0;
        cin >> n >> d;
        int x[2000001];
        for(int i=1;i<=n;i++) cin >> x[i];
        int s[2000001];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(abs(x[j]-x[k])<=d)s[i]+=abs(x[j]-x[k]);
                    else break;
                }
            }
        }
        int minn=2e9,ans=0;
        for(int i=1;i<=n;i++)minn=min(minn,s[i]);
        for(int i=1;i<=n;i++){
            if(s[i]==minn)cnt++;
        }
        if(cnt==2) ans++;
        cout << ans << endl;
    }

    return 0;
}
