#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);   
int m,n,x=0;
int a[200005];
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for (int i=1;i<=n;i++){
    for(int j=2;i<=n;j++){
        x=max(a[i]&&a[j],x);
        
        
    }
    
    cout<<x;
    
}




return 0;

}
