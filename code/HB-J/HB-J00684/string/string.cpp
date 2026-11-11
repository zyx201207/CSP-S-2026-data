#include <bits/stdc++.h>
using namespace std;
string a[200005];;
string old[200005];
int main (){
freopen("string.in","r",stdin);
freopen("string.out""w",stdout);

string b;
int e,q,m,t,cnt = 0;
int d = 0;
cin >> t;

for (int i = 0;i<t;i++){
   cin >> m;
   cin >> b;
   d+=m;

   for (int j = 0;j<m;j++){
    a[i] = b;
   }
   ;
}
q = d;
e = q/2;
for (int w = q;w>0;w--){
    a[q-w] = old[w-1];
}
for (int r=0;r<q;r++){
    if (a[r]!=old[r]){
            if(r < e){
               cnt+=1;
               }

    }
}
cout << cnt;
return 0;
}
