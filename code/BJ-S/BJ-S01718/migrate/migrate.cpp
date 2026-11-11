
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[1005],b[1005][1050],c[1005],t;
bool ko=0;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>2 && ((a[i]-a[i-1])!=(a[i-1]-a[i-2]))){
                ko=1;
            }
        }
        if(!ko){
            int s=m/(a[2]-a[1]);
            int sw=s*2-1;
            if(sw==1){
                cout<<0;
            }else{
                cout<<n-sw;
            }
        }else{
            cout<<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

