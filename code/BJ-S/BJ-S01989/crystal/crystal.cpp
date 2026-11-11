#include<bits/stdc++.h>
using namespace std;
long long g[500005],lu[500005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long s=m,sum;
    for(int i=1;i<=n;i++){
        sum=1;
        if(i==1){
            for(int j=i+1;j<=n;j++){
                if(s>=a[i]-a[j]){
                    s-=(a[i]-a[j]);
                    sum++;
                }
            }
            if(s!=0){
                lu[i]=s;
            }
        }else{
            if(g[i-1]==1){
                s=lu[i-1];
                for(int j=i+1;j<=n;j++){
                    if(s>=a[i]-a[j]){
                        s-=(a[i]-a[j]);
                        sum++;
                    }
                }
            }else{
            s=(g[i-1]-1)*(a[i-1]-a[i])+lu[i-1];
            sum+=g[i-1]-2;
            for(int j=i+(g[i-1]-1);j<=n;j++){
                if(s>=a[i]-a[j]){
                    s-=(a[i]-a[j]);
                    sum++;
                }
            }
            }
            if(s!=0){
                lu[i]=s;
            }
        }
        g[i]=sum;
    }
    long long maxx=0;
    for(int i=1;i<=n;i++){
        if(maxx<g[i])maxx=g[i];
    }
    cout<<maxx;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
