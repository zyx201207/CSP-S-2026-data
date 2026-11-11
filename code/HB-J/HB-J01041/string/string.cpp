#include<bits/stdc++.h>
using namespace std;
long long n,a[20001],l,r,ans;
string c[20001];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
}
l=1;
r=n;
while(l<r){
    if(c[l]==c[r]){
        if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }else if(a[l]==a[r]){
            l++;
            r--;
        }else{
            a[l]-=a[r];
            r--;
        }
    }else{
        if(a[l]<a[r]){
            ans+=a[l];
            a[r]-=a[l];
            l++;
        }else if(a[l]==a[r]){
            ans+=a[l];
            l++;
            r--;
        }else{
            ans+=a[r];
            a[l]-=a[r];
            r--;
        }
    }
}
cout<<ans<<endl;
return 0;
}
