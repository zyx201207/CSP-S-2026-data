#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,b[MAXN],num[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        int a[MAXN]={},f[MAXN]={},cnt=0;
        for(int j=i;j<n;j++){
            int x=b[j];
            if(f[x]==0){
                a[cnt]=x;
                f[x]=cnt+1;
                cnt++;
            }
            else{
                for(int k=f[x]+1;k<=cnt;k++){
                    a[k]=0;
                    f[k]=0;
                }
                cnt=f[x];
            }
        }
        for(int j=0;j<cnt;j++){
            num[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<num[i]<<' ';
    return 0;
}
