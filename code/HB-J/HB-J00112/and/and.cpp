#include <bits/stdc++.h>
using namespace std;

bool f[32][200005];long long ans;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x,cnt = 1;
        cin >> x;

        while(x!=0){
        if(x%2 == 0)f[cnt][i]=0;
        else f[cnt][i]=1;
        //cout << f[cnt][i] << " ";
        cnt++;
        x/=2;
        }
    }
    for(int i=1;i<=n;i++){
      long long sum = 0;
       for(int z=1;z<=31;z++){
            int flag = 0;
            for(int j=i;j<=m+i;j++){
                if(f[z][j] == 0){
                    flag = 1;

                    break;
                }
            }
            if(!flag){
                sum+=pow(2,z-1);
                //cout << z << " ";
            }
       }
       ans = max(ans,sum);
    }
    cout << ans;


    return 0;
    }
