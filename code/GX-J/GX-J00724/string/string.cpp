#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    scanf("%d",&n);
    long long a[200005]={0};
    char b[200005]={ };
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&b[i]);
    }
    int head=1,ed=n;
    long long sum=0;
    while(head<=ed){
        if(a[head]>a[ed]){
            if(b[head]!=b[ed]){
                sum+=a[ed];
            }
            a[head]-=a[ed--];
        }
        else if(a[head]<a[ed]){
            if(b[head]!=b[ed]){
                sum+=a[head];
            }
            a[ed]-=a[head++];
        }
        else{
            if(b[head]!=b[ed]){
                sum+=a[ed];
            }
            head++;
            ed--;
        }
    }
    cout<<sum;
    return 0;
}
