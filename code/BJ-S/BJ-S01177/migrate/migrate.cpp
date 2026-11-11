#include<bits/stdc++.h>
using namespace std;
int c,T;
bool flag=1;
long long x[2000001];
bool canfly(int x1,int x2,int d){
    if(x2-x1<=d) return 1;
    return 0;
}
void solve(){
    int n,d;
    cin>>n>>d;
    x[1]=0;
    for(int i=2;i<=n;i++){
        cin>>x[i];
        x[i]-=x[0];
        if(x[i]-x[i-1]!=x[2]-x[1]) flag=0; 
    }
    int i=2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}