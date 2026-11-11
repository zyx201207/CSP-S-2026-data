#include<bits/stdc++.h>
using namespace std;
int n,m,b,ans=0;
int a[10086];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;i++)cin>>a[i];
    if(n==2){
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                ans=max(a[i]&a[j],b);
                b=a[i]&a[j];
            }
        }
    }cout<<ans;
    return 0;
}
