#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int a[N],b[N],c[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0) b[a[j]]=j;
            else for(int k=b[a[j++]];k<=j;k++){
                b[a[k]]=0;
            }
        }
        for(int j=i;j<=n;j++){
            if(b[j]!=0){
                c[b[a[j]]]++;
            }
            b[j]=0;
        }
    }
    for(int j=1;j<=m;j++){
        cout<<c[j]<<" ";
    }
    return 0;
}
