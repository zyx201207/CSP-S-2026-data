#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        int x[2000005];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[j-1]>d){
                    break;
                }
                if(a[j]-a[i]<=d){
                    continue;
                }
                if((j-i==3)&&(a[i+2]-a[i]<=d)&&(a[j]-a[i+1]<=d))cnt++;
                if((j-i==4)&&(a[i+2]-a[i]<=d)&&(a[i+3]-a[i+1]<=d)&&(a[j]-a[i+2]>d))cnt++;
                if((j-i==4)&&(a[i+2]-a[i]>d)&&(a[i+3]-a[i+1]>d)&&(a[j]-a[i+2]<=d))cnt++;
                if((j-i==4)&&(a[i+2]-a[i]>d)&&(a[i+3]-a[i+1]<=d)&&(a[j]-a[i+2]<=d))cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}
