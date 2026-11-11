#include<bits/stdc++.h>
using namespace std;
long long n,m,c,t,a[2000005],sum,longg,summ=0;
void fei(long long d,long long num,long long v){
    if(d==v){
        if(num<longg){
            sum=1;
            longg=num;
        }else if(num==longg){
            sum++;
        }
        return;
    }
    if(d>v)return;
    for(int i=d+1;i<=d+m;i++){
        if(a[i]-a[d]<=m){
            fei(i,num+1,v);
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int q=1;q<=t;q++){
        sum=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        longg=n;
        for(long long u=1;u<=n;u++){
            for(long long v=u+1;v<=n;v++){
                longg=n;
                fei(u,0,v);
                if(sum==2){
                    summ++;
                }
                sum=0;
            }
        }
        cout<<summ<<endl;
        for(int i=1;i<=n+1;i++){
            a[i]=0;
        }
        longg=0;
        summ=0;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
