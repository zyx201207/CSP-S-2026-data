#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200010][1000];
char b[200010][1000];
long long R,L;
long long i=1;
long long ans = 0;

void sole(long long q){//shu 2
    R++;
    i++;
    for(int j=1;j<=R-1;j++){
        a[j][i] = a[j][i-1];
        b[j][i] = b[j][i-1];
    }
    a[R-1][i] = q;
    //for(int j=L,m=R;j>=1;j--,m++){
     //   a[m][i] = a[j][i-1];
     //   b[m][i] = b[j][i-1];
    //}
    return ;
}

void sole2(long long q){

    if(b[R][i] != b[L][i]){
       ans += a[R][i];
    }
    R--;q*=-1;
    if(R<=L){
        return ;
    }
    q = a[R][i] - q;
    if(q<0){
        sole2(q);
    }
    if(q==0){
        if(b[R][i] != b[L][i]){
            ans += a[R][i];
        }
        i++;
        for(int j=1;j<=R-1;j++){
            a[j][i] = a[j][i-1];
            b[j][i] = b[j][i-1];
        }
        //for(int j=L,m=R;j>=1;j--,m++){
        //    a[m][i] = a[j][i-1];
        //    b[m][i] = b[j][i-1];
        //}
    }
    if(q>0){
        if(b[R][i] != b[L][i]){
            ans += a[R][i] - q;
        }
        sole(q);
    }
    return ;
}


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int ii=1;ii<=n;ii++){
        scanf("%lld",&a[ii][1]);
        cin >> b[ii][1];
    }

    L=1;R=n;
    long long c=0;

    while(R>=L){
        c = a[R][i] - a[L][i];
        if(c>0){
            if(b[R][i] != b[L][i]){
                ans += a[L][i];
            }
            sole(c);
            n++;
        }
        if(c==0){
            if(b[R][i] != b[L][i]){
                ans += a[L][i];
            }
            i++;
            for(int j=1;j<=R-1;j++){
                a[j][i] = a[j][i-1];
                b[j][i] = b[j][i-1];
            }
            //for(int j=L,m=R;j>=1;j--,m++){
            //    a[m][i] = a[j][i-1];
            //    b[m][i] = b[j][i-1];
            //}
        }
        if(c<0){
            sole2(c);
            if(R==L){
                break;
            }
        }
        L++;R--;
    }
    cout << ans;
    return 0;
}

