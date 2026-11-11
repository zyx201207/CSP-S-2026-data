#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500050],bb[500050],cc[500050];
long long am[5050][5050];bool flagA = true ,flagB = true;

void s1(){
    long long asd = 1,ans = 0;
    while(m>asd){
        m-=asd;
        ans++;
        asd++;
    }
    cout << ans;
    return ;
}

void s2(){
    m/=am[1][2];
    s1();
    return ;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=i){
            flagA = false;
        }
    }
    if(flagA){
        s1();
        return 0;
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++){
        for(long long j=i+1;j<=n;j++){
            am[i][j] = a[j] - a[i];
        }
        if(i>=2 && am[i][i+1] != am[i-1][i]){
            flagB = false;
        }
    }
    if(flagB){
        s2();
        return 0;
    }
    long long c = 0,ans = -1;
    for(long long j=2;j<=n;j++){
        c = 0;
        for(long long i = j - 1;i>=1;i--){
            c += am[i][j];
            if(i==1 && c<=m){
                ans = max(ans,j-i+1);
                break;
            }
            if(c>m){
                ans = max(ans,j-i);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
