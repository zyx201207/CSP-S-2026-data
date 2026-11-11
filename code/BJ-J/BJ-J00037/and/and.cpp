#include<bits/stdc++.h>
using namespace std;
const int MAX=1<<30;
int n,m;
long long ans=0;
int a[200005];
bool no[200005],niulai[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=30;k>=0;k--){
        int pot=1<<k;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if((a[i]&pot)!=0 && !no[i]){
                niulai[i]=1;
                cnt++;
            }
        }
        if(cnt>=m){
            ans=(ans<<1)+1;
            for(int i=1;i<=n;i++){
                if(no[i] || !niulai[i]){
                    no[i]=1;
                }
            }
        }
        else{
            ans=ans<<1;
        }
        memset(niulai,0,sizeof(niulai));
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
