#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
long long a[n]={0};
char c[n];
for(long long i=0;i<n;i++){
    cin>>a[i]>>c[i];
}
int l=0,r=n-1;
int ans=0;
while(l<=r){
    if(c[l]!=c[r]){
        ans+=max(a[l],a[r]);
    }
    l++;
    r--;
}
cout<<ans;




return 0;
}


