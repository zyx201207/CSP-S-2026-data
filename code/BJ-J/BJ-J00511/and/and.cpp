#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,a[MAXN],out,s[MAXN],sh=0;
bool ma[MAXN][30],ans[30];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=29;j>=0;j--){
            ma[i][j]=a[i]%2;
            a[i]>>=1;
        }
    }
    for(int j=0;j<=29;j++){
        for(int i=0;i<n;i++){
            if(ma[i][j])s[sh++]=i;
        }
        if(sh>=m)break;
        for(int i=0;i<sh;i++)s[i]=0;
        sh=0;
    }
    for(int j=0;j<=29;j++){
        ans[j]=1;
        for(int i=0;i<m;i++){
            if(!ma[s[i]][j])ans[j]=0;
            if(!ans[j])break;
        }
    }

    for(int i=0;i<=29;i++){
        out<<=1;
        if(ans[i])out++;
    }
    cout<<out;
    return 0;
}
/*
death is not terrible
death is cool summer night
that makes people sleep in peace with no worries