#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int ans;
int a[500001];
int main(){
    freopen("crystal.in","r",stdin);                                                                                                                                                                    
    freopen("crystal.out","w",stdout);                                                                                                                                                                  
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=(n+1)/2;i>=1;i--){
        if(a[i]!=a[(n+1)/2]||m>=a[(n+1)/2]-a[i]){
            ans++;
            m-=a[(n+1)/2]-a[i];
        }
    }
    cout<<ans+1;
    fclose(stdin);                                                                                                                                                                                      
    fclose(stdout);                                                                                                                                                                                     
}