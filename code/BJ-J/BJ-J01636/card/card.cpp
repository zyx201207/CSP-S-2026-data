#include<bits/stdc++.h>
using namespace std;

struct node {
    int nmb, sta, las;
}m[300005];
int n, m;
int a[500005];
int cc;

int main() {

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int k=1; k<=n; k++) {
        cc=n;
        int sum=0;
        memset (m, 0, sizeof (m));
        for (int i=k; i<=n; i++) {
            if (m[a[i]].nmb>=1){
                cc=a[i];
                m[a[i]].las=i;
            } else {
                m[a[i]].sta=i;
            }
            m[a[i]].nmb++;
        }
        for (int i=k; i<m[cc].sta; i++) {
            if (a[i]==k)   sum++;
        }
        for (int i=m[cc].las; i<=n; i++) {
            if (a[i]=k)   sum++;
        }
        cout << sum << " ";
    }

    return 0;
}