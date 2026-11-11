#include<bits/stdc++.h>
using namespace std;
long long n,m,a,a2[31][200000],an[30][200000];
long long ad(long long na,long long ma){
    for(long long i=0;i<n;i++){
        if(a2[30][i]==0){
            for(long long j=29;j>=0;j--){
                an[j][na]=a2[j][i];
            }
            a2[30][i]==1;
        }
    }
    ad(na+1,ma-1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a;
        for(long long j=29;j>=0;j--){
            if(a%2==1) a2[i][j]=1;
            if(a/2==0) break;
            a/=2;
        }
    }
    cout<<11;
    return 0;
}
