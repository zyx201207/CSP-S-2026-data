#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
 int n;
 long long m;
 cin>>n>>m;
 int a[500005];
 for(int i=1;i<=n;i++){
    cin>>a[i];
 }
 for(int i=n;i>=2;i--){
    for(int j=a[i-1];j<=2;j--){
        a[i]+=a[n]-a[i];
        m-=a[n]-a[i];

    }

 }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
