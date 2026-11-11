#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t,n,d,x[10005]={0};
    cin>>c>>t;
    int sum[1005]={0};
    int minv=1000000;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
        for(int z=0;z<n;z++){
            if(x[z]<minv){
                minv=x[z];
            }
        }
        for(int y=0;y<n;y++){
             if(minv==x[y]){
                sum[i]++;
             }
        }
        sum[i]/=2;
    }

    for(int i=0;i<t;i++){
        cout<<sum[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
