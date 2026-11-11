#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[200001],b1[200001],b2[200001],m1=0,m2=0,sum1=1,sum2=1;
long long s[200001],ans=0;
int c[200010],c1[200001],c2[200001];
char s2;

int main() {
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf ("%d%c%c",&a[i],&s2,&c[i]);
    }
    for (int i=1;i<=n;i++) {
        s[i]=s[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        if (s[i]<=(s[n]+1)/2) {
            m1++;
            b1[m1]=a[i];
            c1[m1]=c[i];
            if (s[i]==(s[n]+1)/2&&s[n]%2==1) {
                b1[m1]--;
            }
        }
        else {
            if (s[i-1]+1<=s[n]/2&&s[i]>(s[n]+1)/2) {
                m1++;
                b1[m1]=s[n]/2-s[i-1];
                c1[m1]=c[i];
                m2++;
                b2[m2]=s[i]-((s[n]+1)/2);
                c2[m2]=c[i];
            }
            else {
                m2++;
                b2[m2]=a[i];
                c2[m2]=c[i];
                if (s[i-1]+1==(s[n]+1)/2&&s[n]%2==1) {
                    b2[m2]--;
                }
            }
        }
    }
    sum2=m2;
    for (int i=1;sum1<=m1&&sum2>=1;i++) {
        int sum=min(b1[sum1],b2[sum2]);
        b1[sum1]-=sum;
        b2[sum2]-=sum;
        if (c1[sum1]!=c2[sum2]) {
            ans+=sum;
        }
        if (b1[sum1]<=0) {
            sum1++;
        }
        if (b2[sum2]<=0) {
            sum2--;
        }
    }
    printf ("%lld",ans);
    return 0;
}
