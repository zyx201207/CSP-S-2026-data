#include<bits/stdc++.h>
using namespace std;
long long a[100010000],b[10001000],l[10000010],len[10000100],lg[10000100];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long n,m,i,j,s=1,f=0,midd,sum = 0;
    long long ma = INT_MIN,lma;
    bool d;
    cin>>n>>m;
    for ( i = 1;i <= n;i ++){
        cin>>a[i];
    }
    for ( i = 1;i <= n;i ++){
        for( j = 1;j <= n;j ++){
            if (i == j) continue;
            if (a[i] < a[j]){
                s ++;
            }
            else if (a[i] == a[j]){
                f++;
                d = true;
            }
        }
        l[s] = f;
        b[s] = a[i];
        if  (f > 0) {
            for( j = f;j >= 1;j --){
                b[s+j] = a[i];
            }
        }
        s = 1;
        f = 0;
    }
    s = 1;
    f = 0;
    cout<<"1"<<endl<<"2";
    if( d == 1){
        for ( i = 1;i <= n;i ++){
            if(l[i] > ma){
                ma = l[i];
                lma = b[i];
            }
        }
        for( i = 1;i <= n;i ++){
            if( a[i] >= ma){
                len[i] = a[i] - lma;
                cout<<"@";
            }
            else {
                len[i] = lma - a[i];
                cout<<"#";
            }

        }
        for ( i = 1;i <= n;i ++){
            for( j = 1;j <= n;j ++){
                if (i == j) continue;
                if (len[i] < len[j]){
                    s ++;
                }
            else if (len[i] == len[j]){
                f++;
            }
        }
        //cout<<s<<" "<<f<<" "<<endl;
        lg[s] = lg[i];
        if  (f > 0) {
            for( j = f;j >= 1;j --){
                lg[s+j] = len[i];
            }
        }
        s = 1;
        f = 0;
        }

    }
    return 0;
}
