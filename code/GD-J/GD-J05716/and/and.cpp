#include<bits/stdc++.h>
using namespace std;
long long ma=0,n,m,maxk=0;
long long A[200010];
bool f;
bool bmp(long long a,long long b){
    return a>b;
}
void dfs(int a,int k,long long w){
    if(k==0){
        ma=max(ma,w);
        if(ma==maxk){
            f=true;
        }
        return;
    }
    for(int i=a;i<n;i++){
        if(n-i<k){
            break;
        }
        dfs(i+1,k-1,(w&A[i]));
        if(f){
            return;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>A[i];
        maxk=max(maxk,A[i]);
    }
    sort(A,A+n,bmp);
    dfs(0,m,2147483647);
    cout<<ma;
    return 0;
}
