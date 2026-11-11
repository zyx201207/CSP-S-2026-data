#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int a[N],b[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    cin>>T>>T;
    for(int o=1;o<=T;o++){
        int n,m,sum=0,x=1,cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1 && a[i]-a[i-1]>m)    cnt++;
            b[i]=cnt;
        }
        for(int i=1;i<=cnt;i++){
            for(x;1;x++){
                if(b[x]!=i) break;
                for(int j=1;j<=n;j++){
                    if(b[j]!=i)             break;
                    if((a[j]-a[x])%m!=0)    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
