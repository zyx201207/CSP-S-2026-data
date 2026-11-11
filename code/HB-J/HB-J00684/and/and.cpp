#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int d[2000005];
int main (){
freopen("and.in""r",stdin);
freopen("and.out""w",stdout);
int now,maxn,c,b,e;
cin >> b;
cin >> c;
for(int i = 0;i<b;i++){
    cin >> a[i];
    e+=1;
}
for (int j = 0;j<e;j++){
    for(int l = 0;l<c;l++){
            for (int h = 0;h<e;h++){
                maxn =  a[j] = a[j]&a[h];
for(int j = 0;j < e;j++){
}
    for (int k = 0;k<e;k++){
        if(j == k){
            continue;
        }
        else{
            for(int l = 0;l<c;l++){
               for (int h = 0;h<e;h++){
                 now = a[j] = a[j]&a[h];

                 if (now>maxn){
                    maxn = now;
                 }
               }
            }
        }
    }
}}
}
cout << maxn;
return 0;
}
