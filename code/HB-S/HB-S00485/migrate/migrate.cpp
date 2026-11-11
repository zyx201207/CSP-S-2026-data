#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long dy[200005];
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d,sum;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>dy[j];
        }
        for(int j=0;j<n;j++){
            dy[j]=dy[j+1]-dy[j];
        }
        sum=n-2;
        for(int j=0;j<n-1;j++){
            if(dy[j]==dy[j+1]&&dy[j+1]!=1){
                sum--;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
