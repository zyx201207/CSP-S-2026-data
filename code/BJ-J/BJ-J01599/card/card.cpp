#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],b[M];
bool a1[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        memset(a1,0,n+1);
        for(int j=i;j<=n;j++){
            bool l=0;
            for(int k=i;k<j;k++){
                if(a1[k]) continue;
                else {
                    if(a[k]==a[j]) l=1;
                    a1[k]=l;
                }
            }
        }for(int j=i;j<=n;j++){
            if(!a1[j]) b[a[j]]++;
        }
    }for(int i=1;i<=m;i++) cout<<b[i]<<' ';
    return 0;
}
