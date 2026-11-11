#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int c;
int n,t;
long long d;
long long x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        long long tmp=n,D=x[2]-x[1];
        long long p=d/D;
        long long ans=tmp-(p+1);
        if(ans<=0||p+1>=n){
            cout<<0<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
