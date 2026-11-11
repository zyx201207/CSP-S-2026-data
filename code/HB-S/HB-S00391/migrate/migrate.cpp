#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long c,t,n,d;
long long x[N];
long long sum=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                if(x[k]-x[j]>d&&(x[k]-x[j])%d!=0){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

