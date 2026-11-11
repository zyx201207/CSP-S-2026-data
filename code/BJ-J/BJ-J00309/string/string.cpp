#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum=0,ans=0;
char c[200005],m[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
}
int cnt=1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=a[i];j++){
        m[cnt]=c[i];
        cnt++;
    }
}
int mid=cnt/2;
if(cnt%2!=0){
for(int i=1;i<=mid;i++){
    if(m[mid+i]!=m[mid-i]) ans++;
}
}
else {
    for(int i=0;i<=mid;i++){
    if(m[mid+i]!=m[mid-i+1]) ans++;
    }
}
cout<<ans;
}
