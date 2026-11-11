#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
long long len=0;
long long n;
vector <char> str;
int a[200000+10];
char t[200000+10];
long long maxn=-1000000010;
long long gcd(int *p) {
    int res=1;
    for (long long j=maxn;j>=1;j--) {
        bool s=1;
        for (long long i=1;i<=n;i++) {
            if (a[i]%j!=0) {
                s=0;
                break;
            }
        }
        if (s) {
            res=j;
            return res;
        }
    }
    return res;
}
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //
    scanf("%lld",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        getchar();
        scanf("%c",&t[i]);
        len+=a[i];
        if (a[i]>maxn)maxn=a[i];
    }
    long long sum_gcd=gcd(a);
    //printf("%d",sum_gcd);
    //
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=a[i];j+=sum_gcd) {
            str.push_back(t[i]);
        }
    }
    //
    len/=sum_gcd;
    long long ans=0;
    for (int i=0;i<len;i++) {
        if (str[i]!=str[len-i-1]) {
            ans++;
        }
    }
    ans/=2;
    //printf("%d\n",sum_gcd);
    printf("%lld\n",ans*sum_gcd);
    /*for (char v : str) {
        printf("%c",v);
    }*/
    return 0;
}
