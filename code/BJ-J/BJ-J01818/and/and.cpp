#include<bits/stdc++.h>
using namespace std;
long long n,m,h,a[10010];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
cin>>n>>m;
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
long long t=n,l=n;
for(long long i=1;i<=m;i++){
    h=a[t];
    if(m>=2){
        for(int j=1;j<=m;j++){
            h=a[l]&a[l--];
            l=l--;
        }
        break;
    }
    else{
        h=a[n];
        break;
    }
    t--;
}
cout<<h;
return 0;
}
