#include <bits/stdc++.h>

using namespace std;

int n,m,cnt=0;
int a[200005];
int pai[200005];

int h[100005];

int ffind(int x) {
    for(int i=1;i<=cnt;i++) {
        if(pai[i]==x) return i;
    }
    return -1;
}

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }

    for(int i=1;i<=n;i++) {
        memset(pai,0,sizeof(pai)); cnt=0;
        for(int j=i;j<=n;j++) {
            if(ffind(a[j])!=-1) {
                for(int k=ffind(a[j])+1;k<=cnt;k++) pai[k]=0;
                cnt=ffind(a[j]);
            }
            else {
                pai[++cnt]=a[j];
            }
        }
        //for(int j=1;j<=cnt;j++) cout << pai[j] << ' ';
        //cout << endl << endl;
        for(int j=1;j<=cnt;j++) {
            h[pai[j]]++;
        }
    }

    for(int i=1;i<=m;i++) {
        cout << h[i] << ' ';
    }

    return 0;
}
