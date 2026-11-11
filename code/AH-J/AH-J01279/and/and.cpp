#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1;
long long a[1000100];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<m;j++){
            if(i==0){
            if(a[i]&a[n]>maxn){
                maxn=a[i]&a[n];
            }
        }else if(i>=0){
            if(a[i]&a[i-1]>maxn){
                maxn=a[i]&a[i-1];
            }else if(a[i]&a[i+1]>maxn){
                maxn=a[i]&a[i+1];
            }else{
                continue;
            }
        }
        }
    }
    cout<<maxn;
    return 0;
}
