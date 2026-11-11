#include <bits/stdc++.h>
using namespace std;
int a[200005];


int b[200005];
int c[200005];
int main(){
freopen("card.in""r",stdin);
freopen("card.out""w",stdout);
int n,cnt;
int m;
cin >> m;
for(int d = 0;d<m;d++){
    cin >> a[d];
}

for(int l = 0;l<m;l++){
    for (int i = l;i<m;i++){
    for (int j = i+1 ;j<m;j++){
        if (a[i] == a[j]){
            cnt = j;
            n+=1;
            for(int h = cnt;h,n;h++){
a[h] = b[h-cnt];
}
for(int f = 1;f<=n;f++){
    for (int k = 0;k<n;k++){
   if (b[k] == f){
       c[f]+=1;
       }
}

}}}}}
for(int s = 0;s<n;s++){
    cout << c[s];
}
return 0;
}
