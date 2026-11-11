#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+5;
long long a[N],cnt=0,d;
bool check(long long i,long long j,long long mintot){
    for(;j-i<=d;i++){
        if(check(i,j,mintot-1))cnt++;
    }
    if(cnt=2)return 1;
    else return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    long long t;
    cin>>c>>t;
    for(int k=t;k>=1;k--){
        long long n,tot=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=d+1&&t>1){
            cout<<"0"<<endl;continue;
        }
        else if(n<=d+1&&t==1){
            cout<<"0";continue;
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i+d+1;j<=n;j++){
                long long mintot=(j-i)/d;
                cnt=0;
                if(check(i,j,mintot)){
                    tot+=1;
                }
            }
        }
        if(k!=1)cout<<tot<<endl;
        else cout<<tot;
    }
    return 0;
}