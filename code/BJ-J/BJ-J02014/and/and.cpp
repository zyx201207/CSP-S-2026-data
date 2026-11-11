#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],maxx=0,f[300005];
long long ci(long long n,long long i){
    for(int j=1;j<=i-1;j++){
        n*=n;
    }
    return n;
}
long long andd(long long x,long long y){
    long long sum=0;
    for(int i=20;i>=0;i++){
        if(i==0){
            if(x!=0&&y!=0){
                x-=1;
                y-=1;
                sum+=1;
            }
        }else if(x-ci(2,i)>=0&&y-ci(2,i)>=0){
            x-=ci(2,i);
            y-=ci(2,i);
            sum+=ci(2,i);
        }
    }
    return sum;
}
void de(long long j,long long sum){
    j++;
    if(j==m){
        if(maxx<sum)sum=maxx;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            de(j,andd(sum,a[i]));
            f[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        de(1,a[i]);
    }
    cout<<maxx;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
