#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long c[300010];
long long last[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        last[a[i]]=i;
    }
    long long left;
    for(int k=1;k<=n;k++){
        left=k;
        while(left<=n){
            c[a[left]]++;
            left=last[a[left]]+1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
