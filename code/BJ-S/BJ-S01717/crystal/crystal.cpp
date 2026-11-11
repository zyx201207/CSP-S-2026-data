#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=1,a[500005];
/*bool xywty(int l,int r){
    int mid=(l+r)/2,s=0;
    for(int i=l;i<=mid;i++){
        s+=a[mid]-a[i]
    }
}*/
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
        long long s=0,k=m;
    for(int j=i;j<=n;j++){
        long long cur=(j-i)*(a[j]-a[j-1]);
        if(k>=cur){
            s++;k-=cur;
        }
        else break;
    }
    //cout<<s<<endl;
    ma=max(ma,s);
}
cout<<ma;
return 0;
}
