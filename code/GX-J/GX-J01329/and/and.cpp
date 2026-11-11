#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,num[1000000];
int andt(int a,int b){
    long long int ans=0;
    int i=0;
    while(1){
        int ta = a%2,tb = b%2;
        cout<<a<<b;
        if(ta==tb){
            long long int t=1;
            for(int j=1;j<=i;j++) t*=2;
            ans+=t;
        }
        i++;
        a=a/2;
        b=b/2;
        if(a==0 || b==0) break;
    }
    return ans;
}
void sum(int n,int a,int b){
    if(n==m){
        maxn=max(maxn,andt(a,b));
    }
    if(n==2){
        for(int i=0;i<n-m;i++){
            for(int j=i+1;j<=n-m-1;j++){
                sum(3,andt(i,j),j+1);
            }
        }
    }
    else{
        for(int i=b;i<=n;i++){
            sum(n+1,andt(a,b),b+1);
        }
    }
    return ;
}
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[n];
    }
    sum(2,0,0);
    cout<<maxn;
    return 0;
}
