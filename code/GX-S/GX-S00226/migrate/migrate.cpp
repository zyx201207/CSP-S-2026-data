#include<bits/stdc++.h>
using namespace std;
int c, t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int j = 1; j <= t; j++){
        int n, d;
        int x[2000005]={}, pref[2000005]={};
        cin>>n>>d;
        cin>>x[1];
        pref[1]=0;
        int id=0;
        for(int i = 2; i <= n; i++){
            cin>>x[i];
            pref[i]=pref[i-1]+(x[i]-x[i-1]);
            if(pref[i]>d&&id==0) id=i;
        }
        memset(pref,1,id);
        for(int i = id; i <= n; i++){
            for(int k = 1; k < d; k++){
                pref[i] += pref[i-k];
                cout<<pref[i];
                pref[i]=1;
            }
        }

    }
    cout<<1;
    return 0;
}
