#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct Node{
    long long sum;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld %c",&a[i].sum,&a[i].c);
    long long ans=0;
    int l=0,r=n;
    while(l<r){
        if(a[l].c==a[r].c){
            if(a[l].sum==a[r].sum)l++,r--;
            else if(a[l].sum<a[r].sum){
                a[r].sum-=a[l].sum;
                l++;
            }
            else{
                a[l].sum-=a[r].sum;
                r--;
            }
        }else{
            if(a[l].sum==a[r].sum){
                ans+=a[l].sum;
                l++,r--;
            }
            else if(a[l].sum<a[r].sum){
                a[r].sum-=a[l].sum;
                ans+=a[l].sum;
                l++;
            }
            else{
                a[l].sum-=a[r].sum;
                ans+=a[r].sum;
                r--;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
