#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n[10001],d[10001],cnt[10001];
long long p[10001][10001];
bool canfly(long long ki,long long x){
    if((x==1&&p[ki][x+1]-p[ki][x]<=d[ki])||(x==n[ki]&&p[ki][x]-p[ki][x-1]<=d[ki])||(x>1&&x<n[ki]&&p[ki][x+1]-p[ki][x]<=d[ki]||p[ki][x]-p[ki][x-1]<=d[ki])) return true;
    else return false;
}
int main(){
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        cin>>n[i]>>d[i];
        for(long long j=1;j<=n[i];j++){
            cin>>p[i][j];
        }
        cnt[i]=0;
        for(long long j=1;j<=n[i]-1;j++){
            for(long long k=j+1;k<=n[i];k++){
                if(canfly(i,j)&&canfly(i,k)&&(p[i][k]-p[i][j])>d[i]&&(p[i][k]-p[i][j])%d[i]==d[i]-1){
                    cnt[i]++;
                }
            }
        }
    }
    for(long long i=1;i<=t;i++){
        cout<<cnt[i]<<endl;
    }
    return 0;
}
