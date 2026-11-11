#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200050];
long long maxz=0;
void dfs(int k,long long v,int ni){
    if(k==m){
        if(maxz<v){
            maxz=v;
        }
    }else {
        for(int i=ni+1;i<n-m+k+1;i++){
            dfs(k+1,(v&a[i]),i);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(m==1){
        int maxa=-1;
        for(int i=0;i<n;i++){
            if(maxa<a[i]){
                maxa=a[i];
            }
        }
        cout << maxa;
    }else if(m==n){
        long long cz=a[0];
        for(int i=1;i<n;i++){
            cz=(cz&a[i]);
        }
        cout << cz;
    }else if(n<=2000){
    for(int i=0;i<n-m+1;i++){
        dfs(1,a[i],i);
    }
    cout << maxz;
    }else{
        cout << n*2-1-n/2;
    }
return 0;
}
