#include<bits/stdc++.h>
using namespace std;
int n,m,c,ans=0,v=0,s;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m=1){
        for(int i=1;i<=n;i++){
            v=max(a[i],v);
        }
        cout<<v;
    }
    else if(m=n){
        for(int i=1;i<n;i++){
            s=a[i]&a[i+1];
        }
        cout<<s;
    }
    else{
    for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                c=a[i]&a[j];
                if(c>ans)ans=c;
            }
        }
    }
    cout<<ans;
    return 0;
}

