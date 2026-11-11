#include<bits/stdc++.h>
using namespace std;
const long long MAXN=500001;
long long m,n,a[MAXN],cnt=0,c;
int main(){
    freopen("crystal.in","r",stdin);
     freopen("crystal.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
        cin>>a[i];

     }
     for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(a[i]<a[j])
            swap(a[i],a[j]);
    }
}
int mx=0;
for(int i=1;i<=n;i++){
    int s=0;
    for(int j=1;j<=i;j++){
        s+=a[i]-a[j];
    }
    if(s<=m&&i>mx){
        mx=i;
    }
}
cout<<mx;
return 0;
}

