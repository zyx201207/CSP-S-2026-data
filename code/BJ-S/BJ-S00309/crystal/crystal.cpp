#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ci,ans=-1,cnt,b[500010],qem;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++){
        b[i]=a[i];
    }
    for(long long i=1;i<=n;i++){
        ci=i;
        cnt=0;qem=0;
        for(long long j=1;j<=m;){
            if((ci>n)){
                break;
            }
            if((b[ci]+qem)<a[i]-1000000000){
                qem+=1000000000;
                j+=1000000000;
            }
            else if((b[ci]+qem)<a[i]-100000000){
                qem+=100000000;
                j+=100000000;
            }
            else if(b[ci]+qem<a[i]-50000000){
                qem+=50000000;
                j+=50000000;
            }
            else if(b[ci]+qem<a[i]-10000000){
                qem+=10000000;
                j+=10000000;
            }
            else if(b[ci]+qem<a[i]-5000000){
                qem+=5000000;
                j+=5000000;
            }
            else if(b[ci]+qem<a[i]-1000000){
                qem+=1000000;
                j+=1000000;
            }
            else if(b[ci]+qem<a[i]-100000){
                qem+=100000;
                j+=100000;
            }
            else if(b[ci]+qem<a[i]-50000){
                qem+=50000;
                j+=50000;
            }
            else if((b[ci]+qem)<a[i]-30000){
                qem+=30000;
                j+=30000;
            }
            else if((b[ci]+qem)<a[i]-10000){
                qem+=10000;
                j+=10000;
            }
            else if((b[ci]+qem)<a[i]-5000){
                qem+=5000;
                j+=5000;
            }
            else if((b[ci]+qem)<a[i]-2500){
                qem+=2500;
                j+=2500;
            }
            else if((b[ci]+qem)<a[i]-1000){
                qem+=1000;
                j+=1000;
            }
            else if((b[ci]+qem)<a[i]-500){
                qem+=500;
                j+=500;
            }
            else if((b[ci]+qem)<a[i]-100){
                qem+=100;
                j+=100;
            }
            else if((b[ci]+qem)<a[i]-50){
                qem+=50;
                j+=50;
            }
            else if((b[ci]+qem)<a[i]-25){
                qem+=25;
                j+=25;
            }
            else if((b[ci]+qem)<a[i]-10){
                qem+=10;
                j+=10;
            }
            else if((b[ci]+qem)<a[i]-5){
                qem+=5;
                j+=5;
            }
            else if(b[ci]+qem<a[i]){
                qem++;
                j++;
            }
            if((b[ci]+qem)==a[i]){
                ci++;
                cnt++;
                qem=0;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
