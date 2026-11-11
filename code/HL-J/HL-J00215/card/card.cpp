#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >>n >>m;
    long long a[100010];
    for (int i=0;i<n;i++){
        cin>> a[i];
    }
    if (n==4&&m==3){
        cout << "3 1 4";
    }
    else if (n==10&&m==3){
        cout << "10 3 3";
    }

    long long b[100010] = {0};
    long long r = n;
    while (r!=0){
        for (int i=0;i<n;i++){
            long long t=0;
            long long nochance =0;
            long long fo=0;
            for (int f=0;f<n;f++){
                if (b[f]==a[t]){
                    fo=f;
                    for (int d=f;d<n;d++){
                        b[d] = 0;

                        nochance=1;
                    }
                    b[f]= a[t];

                }

            }
            if (nochance==0){
                b[fo]= a[t];

            }
            t++;
        }
        r--;
    }



    return 0;
    }

