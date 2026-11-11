#include<bits/stdc++.h>
using namespace std;
struct T{
    char st;
    long long shu;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,x,sum=0;
    char c;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        cin>>c;
        a[i].shu=x,a[i].st=c;
    }
    long long l=1,r=n;
    while(l<r){
        if(a[l].shu<a[r].shu){
            if(a[l].st!=a[r].st){
                sum+=a[l].shu;
                l++;
            }else{
                l++;
            }
            a[r].shu-=a[l-1].shu;
        }else if(a[l].shu==a[r].shu){
            if(a[l].st!=a[r].st){
                sum+=a[l].shu;
            }
            l++,r--;
        }else{
            if(a[l].st!=a[r].st){
                sum+=a[r].shu;
                r--;
            }else{
                r--;
            }
            a[l].shu-=a[r+1].shu;
        }
    }
    printf("%lld",sum);
    return 0;
}
