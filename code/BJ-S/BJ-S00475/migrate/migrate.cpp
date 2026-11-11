#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
long long c,t,n,d,a[N],k,cnt;
void dfs(int l){
    int sum=0;
    if(2*d+l-1<=n){
        for(int i=l+1;i<=2*d+l-1;i++){
            if(abs(a[i]-a[i-1])>d){
                sum++;
                break;
            }
        }
        if(sum==0){
            cnt++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        cnt=0;
        for(int j=1;j<=n;j++){
            dfs(j);
        }
        cout<<cnt<<endl;
    }
    return 0;
}


