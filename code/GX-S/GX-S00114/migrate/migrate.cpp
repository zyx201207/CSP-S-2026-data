#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long n,m,a[10000000000005],cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        while(m){
            if(i%2!=0){
                if(a[i]!=a[i+1]&&a[i]!=a[i+2]&&m!=0){
                    a[i]+=1;
                    m--;
                }else{
                    a[i+1];
                }
            }else{
                if(a[i]!=a[i+1]&&m!=0){
                    a[i]+1;
                    m--;
                }

            }
            }
        }
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                cnt++;
            }
        }

    return 0;
}
