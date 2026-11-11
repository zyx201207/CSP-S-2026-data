#include<bits/stdc++.h>
using namespace std;

int a[10005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=a[1];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=0,p;
        while(a[i]&a[i+1]){
              p==a[i]&a[i+1];
              cnt+=p;
              if(cnt>mx){
                mx==cnt;
              }
        }
    }
    cout<<mx<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
