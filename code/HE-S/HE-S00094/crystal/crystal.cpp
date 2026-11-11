#include <bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int cnt=2,j;
int main () {
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long m,n;
scanf("%d %d",&n,&m);
for(int i=1; i<=n;i++){
scanf("%d",&a[i]);
b[i]=a[i];
}
int z=n-1;
while(m--){
if(z==0) z=n;
while(1) {
if(z==0) z=n;
if(a[z]*2+a[1]*(m-2)<=a[n]){
b[z]=a[z]+b[z];
z--;
break;
}
z--;
}
}

for(int x=1;x<=n-1;x++){
for(int y=x+1;y<=n;y++){
if(b[x]==b[y]) cnt++;
}
}
printf("%d",cnt);
return 0;
} 
