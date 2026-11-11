#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T;
int n,d;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            if(abs(a[i+1]-a[i])!=(d-1)){
                cnt++;
            }
        }
        n-=cnt;
        if((n-1)<(d+(d-1))){
            cout<<0<<endl;
            continue;
        }
        if((n-1)%(d+1)==0){
            cout<<(n-1)/(d+(d-1))<<endl;
        }else if((n-1)%(d+(d-1))!=0){
            cout<<(n-1)/(d+(d-1))+1<<endl;
        }
        memset(a,0,sizeof(a));
    }
}
