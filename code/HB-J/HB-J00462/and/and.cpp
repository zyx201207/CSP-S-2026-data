#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],maxn=-1,mn=-1,j,x=INT_MAX;
void dfs(int k,int s)
{
    if(k==0){
        cout<<s;
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]&s>mn&&a[i]!=0){
                mn=a[i]&s;
                j=i;
            }
        }
        a[j]=0;
        dfs(k-1,mn);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxn){
            maxn=a[i];
        }
        x&=a[i];
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        cout<<x;
        return 0;
    }
    dfs(m+1,INT_MAX);
    return 0;
}
