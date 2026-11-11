#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005],b[200005];
ll sum1,sum2,ans,tot;
char c[200005],C[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int tmp=n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        b[tmp]=a[i],C[tmp]=c[i];
        tmp--;
        tot+=a[i];
    }
    if(tot/2<=50000000) {
        char lc[tot/2+5]={""};char lcc[tot/2+5]={""};
        int now=1;
        sum1=1;
        while(sum1<=tot/2) {
            for(int i=1;i<=a[now];i++) {
                if(i>tot/2) {
                    break;
                }
                lc[sum1]=c[now];
                sum1++;
            }
            now++;
        }
        now=1;
        sum2=1;
        while(sum2<=tot/2) {
            for(int i=1;i<=b[now];i++) {
                if(i>tot/2) {
                    break;
                }
                lcc[sum2]=C[now];
                sum2++;
            }
            now++;
        }
        for(int i=1;i<=tot/2;i++) {
            if(lc[i]!=lcc[i]) ans++;
        }
        cout<<ans;
    }
    else {
		cout<<tot/2;
	}
    return 0;
}
