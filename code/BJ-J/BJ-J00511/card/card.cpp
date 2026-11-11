#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,est[MAXN],lst[MAXN],ans[MAXN],a[MAXN];
bool s1;
void solve1(){
    for(int i=1;i<=m;i++){
        ans[i]=1+lst[i];
    }
}
void solve2(){
    int st[MAXN],sh=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int k=sh;
            for(k;k>0;k--){
                if(st[k]==a[j])break;
            }
            if(k)sh=k-1;
            st[++sh]=a[j];
            //for(int u=1;u<=sh;u++)cout<<st[u]<<' ';cout<<'\n';
        }
        for(int j=1;j<=sh;j++){
            ans[st[j]]++;
        }
        sh=0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!est[a[i]])est[a[i]]=i;
        lst[a[i]]=i;
    }
    s1=1;
    for(int i=0;i<n;i++){
        if(a[i]<a[i-1]){
            s1=0;
            break;
        }
    }
    if(s1)solve1();
    else solve2();
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
/*
T1T2T3 is so easy
but I don't want to attack with T4
so I stop thinking
 cccccccccccccccccc                  cccccccccccccccc             ffffffffffffff
ccccccccccccccccccc                 ccccccccccccccccc             ffffffffffffff
cc                                  cc                            ff
cc                                  cc                            ff
cc                                  cc                            ffffffffffffff
cc                                  cc                            ffffffffffffff
cc                                  cc                            ff
cc                                  cc                            ff
ccccccccccccccccccc                 ccccccccccccccccc             ff
 cccccccccccccccccc                  cccccccccccccccc             ff
 maybe I have a bit talent in drawing
 */