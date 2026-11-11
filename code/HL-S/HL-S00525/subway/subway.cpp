#include <bits/stdc++.h>

using namespace std;
const int N=2*1e6+5;
typedef long long ll;
ll woshiheyao,t,n,d,a[N];
int main()
{
    scanf("%lld%lld",&woshiheyao,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        bool pd=1;
        for(int i=1;i<n;i++){
            if(a[i+1]-a[i]!=a[2]-a[1]){
                pd=0;
                break;
            }
        }
        if(pd){
            if(a[2]-a[1]>d){
                printf("0\n");
            }
            else{

            }
        }
        else
            printf("0\n");
    }
    return 0;
}
