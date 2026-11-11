#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,ans;
long long x[5005];
struct nd{
    int len;
    long long num;
};
nd a[5005][5005];
void inp(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    ans=0;
    return;
}
void solve(){
    inp();
    for(int l=1;l<n;l++){
        for(int i=1,j;i+l<=n;i++){
            j=i+l;
            a[i][j]={2000005,0};
            if(x[j]-x[i]<=d){
                a[i][j]={1,1};
                continue;
            }
            for(int k=i+1;k<j;k++){
                if(a[i][k].len+a[k][j].len<a[i][j].len){
                    if(a[i][j].num==2){
                        ans--;
                    }
                    a[i][j].len=a[i][k].len+a[k][j].len;
                    a[i][j].num=a[i][k].num*a[k][j].num;
                    if(a[i][j].num==2){
                        ans++;
                    }
                }
                else if(a[i][k].len+a[k][j].len==a[i][j].len){
                    if(a[i][j].num==2){
                        ans--;
                    }
                    a[i][j].num=min(a[i][j].num+a[i][k].num*a[k][j].num,3*1LL);
                    if(a[i][j].num==2){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
