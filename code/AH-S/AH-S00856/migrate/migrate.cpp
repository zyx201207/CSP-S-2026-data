#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n,d,cnt;
int a[N];
int fs(int x,int dx){
    if(!dx){
        int p=upper_bound(a+1,a+n+1,a[x]+d)-a;
        return p;
    }
    int p=lower_bound(a+1,a+n+1,a[x]-d)-a;
    return p+1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]+d<a[j]&&fs(i,0)!=fs(j,1))cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
