#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[505],k[505],a[505][505],t[505][505];
int x[100005],y[100005];
int mp[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[j][k[i]] >> t[j][k[i]];
            if(i==1) mp[j][k[i]]=a[j][k[i]];
        }
    }
    for(int i=1;i<=q;i++){
        cin >> x[i] >> y[i];
        int sum=w[x[i]]+w[y[i]];
        int a1,b1,a2,b2;
        for(int j=1;j<=n;j++){
            for(int z=1;z<=k[j];z++){
                if(a[j][z]==x[i]){
                    a1=j;
                    a2=z;
                    break;
                }
            }
        }

        for(int j=1;j<=n;j++){
            for(int z=1;z<=k[j];z++){
                if(a[j][z]==y[i]){
                    b1=j;
                    b2=z;
                    break;
                }
            }
        }
        if(a1==b1){
            for(int j=a2;j<=b2;j++){
                sum+=t[a1][j];
            }
        }else{
            for(int j=a1;j<b1;j++){
                for(int z=j+1;z<=b1;z++){
                    for(int aa=1;aa<=k[j];aa++){
                        for(int bb=1;bb<=k[z];bb++){
                            if(a[j][aa]==a[z][bb]){
                                sum+=t[j][aa];
                            }
                        }
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
