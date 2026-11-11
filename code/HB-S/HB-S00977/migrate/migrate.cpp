#include <bits/stdc++.h>
using namespace std;

int c, t, n, d, x[5000001], ans;

bool two(int a, int b){
    int num=0;
    for(int i=a+1;i<b;i++){
        if(x[a+1]-x[a]<=d && x[b]-x[a+1]<=d){
            num++;
        }
    }
    if(num==2){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(x[j]-x[i]>d){
                    if(two(i, j)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
