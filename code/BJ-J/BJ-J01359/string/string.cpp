#include<bits/stdc++.h>
using namespace std;
struct node {
    long long len;
    char d;
}a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n;
    cin>>n;
    long long num=0;
    long long sum=0;
    int b;
    char c;
    for(int i=1;i<=n;i++) {
        cin>>b>>c;
        num+=b;
        if(a[i-1].d==c) {
            a[i-1].len+=b;
            n--;
            i--;
        }
        else {
            a[i].len=b;
            a[i].d=c;

        }
    }


    for(int i=1;i<=n;i++) {
        sum+=a[i].len;
        if(sum>(num/2)) {
            n++;
            for(int j=n;j>i;j--) {
                a[j].len=a[j-1].len;
                a[j].d=a[j-1].d;
            }
            a[i+1].len=sum-(num+1)/2;
            a[i+1].d=a[i].d;
            a[i].len-=(sum-num/2);
            break;
        }
    }
    long long ans=0,r=n,l=1;
    num/=2;
    while(r-l>1) {
        if(a[l].d!=a[r].d) {

            if(a[l].len<a[r].len) {
                ans+=a[l].len;
                a[r].len-=a[l].len;
                l++;
            }
            else {
                ans+=a[r].len;
                a[l].len-=a[r].len;
                r--;
            }
        }
        else {
            if(a[l].len<a[r].len) {
                a[r].len-=a[l].len;
                l++;
            }
            else {
                a[l].len-=a[r].len;
                r--;
            }
        }
    }
    cout<<ans;

    return 0;
}
