#include <bits/stdc++.h>
using namespace std;
struct pi {
    long long a;
    char b;
};
int main () {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int s;
    cin>>s;
    if (s==1) {
        cout<<0;
        return 0;
    }
    pi c[s+1];
    string l;
    for (int i=1;i<=s;i++) {
        cin>>c[i].a>>c[i].b;
        for (int j=1;j<=c[i].a;j++) {
            l+=c[i].b;
        }
    }
    if (s==2) {
        if (c[1].b==c[2].b) {
            cout<<"0";
        }
        else {
            if (c[1].a>c[2].b) {
                cout<<c[2].a;
            }
            else {
                cout<<c[1].b;
            }
        }
    }
    return 0;
}
