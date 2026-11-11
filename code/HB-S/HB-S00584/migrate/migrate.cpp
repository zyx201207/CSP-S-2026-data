#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MXN=2e6+10;
int c,t;
int n,d;
int pos[MXN];
int bs(int num) {
    int l=1,r=n+1;
    int mid;
    int lst;
    while(l<r) {
        lst=mid;
        mid=(l+r)/2;
        if(lst==mid)
            return mid;
        if(pos[mid]>num)
            r=mid;
        else if(pos[mid]<num)
            l=mid;
        else
            return mid;
        //cout<<l<<' '<<r<<' '<<mid<<endl;
    }
}
signed main() {
    //freopen("migrate4.in","r",stdin);
    //reopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--) {
        cin>>n>>d;
        memset(pos,0x00,sizeof pos);
        bool isA=true;
        int xhj=0;
        cin>>pos[1]>>pos[2];
        xhj=pos[2]-pos[1];
        for(int i=3; i<=n; i++) {
            cin>>pos[i];
            if((pos[i]-pos[i-1])!=xhj)
                isA=false;
        }
        if(n<=3) {
            cout<<0<<endl;
        } else {
            if(isA) {
                if(d+1>=pos[5]||d+pos[1]>=pos[n]||){
                        //(d/xhj)%2!=0||d+pos[1]>=pos[n]||pos[n]%d==0
                    cout<<0<<endl;
                }
                else {
                    if((n-2*(d/xhj)+1)<0){
                        cout<<0<<endl;
                    }else{
                        cout<<n-2*(d/xhj)+1<<endl;
                    }
                }

            } else {
                for(int i=1; i<=n; i++) {
                        int farmx=bs(i+d);
                }
                cout<<d/2<<endl;
            }
        }
    }
    return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
