#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5*100000+5];
int t[5*100000+5];
int maxn,max1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
        if(i>1){
            max1=max(max1,a[i]-a[i-1]);
        }
    }
    sort(a+1,a+n+1,cmp);
    a[0]=INT_MAX;
    a[n+1]=INT_MAX;
    for(int i=1;i<=n;i++){
        int masfi=m;
        int l=i+1;
        int cnt0=0;
        while(1){
                masfi-=(a[i]-a[l]);
                if(masfi<0)break;
                if(a[i]-a[l]!=0)
                    cnt0++;
                l++;
                if(l==n+1)break;
        }
        maxn=max(t[a[i]]+cnt0,maxn);
    }
    if(max1==0)cout<<n;
    else cout<<maxn;
    return 0;
}
