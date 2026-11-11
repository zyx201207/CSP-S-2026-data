#include <iostream>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int m,n;
    string a,b;
    cin >> m;
    cin >> a;
    cin >> n;
    cin >> b;
    int x=a[0]*10+a[1],y=b[0]*10+b[1];

    if(m==n) {
        cout << 1;

    }
    else {
        cout << 0;
    }
    if(m==n&&x==y){
        cout << 1;
    }
    else{
        cout << 0;
    }

    bool flag1=0,flag2=0;
    if(a[2]=='A'||a[2]=='B'||a[2]=='C') flag1=1;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C') flag2=1;

    if(m==n&&x==y&&flag1==flag2) cout << 1;
    else cout << 0;

    if(m==n&&x==y&&flag1==flag2&&abs(a[2]-b[2])!=2){
        cout << 1;
    }
    else cout << 0;

    return 0;
}
