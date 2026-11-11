#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+10,M=3e5+10;
int n,m;
int a[N];
int ds[N];
int tp[M];
int cnt=0;
bool vis1[N][N],vis2[N][N];
int ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        tp[a[i]]++;
    }
    for (int i=1;i<=m;i++){
        if (tp[i]!=0) ds[++cnt]=i;
    }
    for (int i=1;i<=n;i++){
        vis2[i][a[i]]=true;
        for (int j=1;j<=cnt;j++){
            if (vis2[i][ds[j]]==true) continue;
            if (vis2[i-1][ds[j]]==true and a[i-1]!=ds[j]){
                vis2[i][ds[j]]=true;
                continue;
            }
            bool f1=false;
            for (int k=i;k<=n;k++){
                if (a[k]==ds[j]){
                    f1=true;
                    vis2[i][ds[j]]=true;
                    break;
                }
            }
            if (f1==false) vis2[i][ds[j]]=false;
        }
    }
    for (int i=1;i<=n;i++){ // di(i)ju
        vis1[i][a[i]]=true;
        ans[a[i]]++;
        for (int j=i;j<=n;j++){ // di(j)ge
            if (vis1[i][a[j]]==true) continue;
            if (vis2[j+1][a[j]]==false) vis1[i][a[j]]=true;
            bool f=false;
            for (int k=i;k<j;k++){
                if (vis2[j+1][a[k]]==true){
                    f=true;
                    break;
                }
            }
            if (f==false){
                ans[a[j]]++;
                vis1[i][a[j]]=true;
            }
        }
    }
    for (int i=1;i<=m;i++) cout << ans[i] << " ";
    return 0;
}