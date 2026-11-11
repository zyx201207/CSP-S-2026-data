#include <bits/stdc++.h>
using namespace std;
long long a[2005];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long x;
            cin>>x;
            ans=max(ans,x);
        }
        cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
    }
    else if(m==n){
        long long ans=0;
        long long x;
        cin>>x;
        ans=x;
        for(int i=2;i<=n;i++){
            cin>>x;
            ans=ans&x;
        }
        cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
    }
    else if(m==2){
            long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<i;j++){
                    ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
    }
    else{
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long x;
            ans=max(ans,x);
        }
        cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
