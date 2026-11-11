#include<iostream>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long res[m+1]={0},a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=1;k<=n;k++){
        int t[m+1]={0},l=0;
        for(int i=k;i<=n;i++){
            int b=a[i];
            for(int j=0;j<l;j++) if(b==t[j]){
                l=j;
                break;
            }
            t[l++]=b;
        }
        for(int j=0;j<l;j++) res[t[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<' ';
    return 0;
}