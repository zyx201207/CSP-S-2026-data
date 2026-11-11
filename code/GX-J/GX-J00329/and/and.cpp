#include <bits/stdc++.h>
using namespace std;

long long a[1000005],b[1000005];

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,maxn=-1;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}

for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
        b[i]=a[j]&a[i];
    }
}
for(int i=1;i<=n;i++){
    if(b[i]>maxn) maxn=b[i];
    }
cout<<maxn;
return 0;
}

