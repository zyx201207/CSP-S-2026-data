#include<bits/stdc++.h>
using namespace std;
int n,m,jz,a[200001],b[200001];
int zhao(int za,int zb){
    if(zb==1){
       zhao(za+1,b[za+1]);
    }
    b[za]=1;
    return a[za];
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int n,m,maxn=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
            for(int m=j;m<n;m++){
            long long bj=4611686018427387903,bjj;
            for(int l=0;l<m;l++){
                bjj=zhao(m,b[jj]);
                bj=bj&bjj;
            }
            if(maxn<bj)maxn=bj;
        }
        for(int g=0;g<n;g++){
            b[g]==0;
        }
    }
    cout<<maxn;
}