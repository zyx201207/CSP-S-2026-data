#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
const int M=3e5+7;
int n,m;
int a[N];
int t[M],id[M],t1[M];
int p[N];
int sum[M];
int no[2][N];
int ti;
int ch(int x){
    for(int i=0;i<ti;i++){
        if(no[0][i]<=x&&x<=no[1][i]) return 0;
    }
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t1[a[i]]++;
        p[i]=id[a[i]];
        id[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[j]=t1[j];
        }
        ti=0;
        for(int j=1;j<i;j++){
            t[a[j]]--;
        }
        for(int j=i;j<=n;j++){
            if(p[j]>=i){
                if(ch(p[j])){
                    for(int k=p[j];k<j;k++){
                        t[a[k]]--;
                    }
                    no[0][ti]=p[j];
                    no[1][ti]=j-1;
                    ti++;
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(t[j])sum[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
