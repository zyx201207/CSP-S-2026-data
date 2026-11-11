#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M=3e5+10;
int n,m,a[N],cnt[M],g[N];
int lst[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i =1;i<=n;i++) cin>>a[i];
    int ed=0,st;
    for(int i =0;  i< n; i++){
        ed=0;
        memset(lst,-1,sizeof(lst));
        for(int j = i+1;j<=n;j++){
            if(lst[a[j]]!=-1){
                ed=lst[a[j]];
            }else{
                g[++ed]=a[j];
                lst[a[j]]=ed;
            }
        }
        for(int j=1;j<=ed;j++) cnt[g[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;   
}