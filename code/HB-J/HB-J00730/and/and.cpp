#include<bits/stdc++.h>
using namespace std;
long long ma=-1;long long n,m,a[100010];
void an(int id,long long  ans,int be){
    if(id==m){
        ma=max(ma,ans & a[be]);
        return;
        }
    for(int i=be+1;i<=n-(m-id);i++){
        an(id+1,ans&a[be],i);
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-m+1;i++)
    an(1,(1<<20)-1,i);
    cout<<ma;
    return 0;
}
