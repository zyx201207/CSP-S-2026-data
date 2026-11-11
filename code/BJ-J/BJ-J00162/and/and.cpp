#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],s=-1000000000,f;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<=n-k;i++){
    f=0xffffffff;
    for(int j=0;j<k;j++){
        f&=a[i+j];
    }
    if(f>s)s=f;
}
cout<<s;
fclose(stdin);
fclose(stdout);
return 0;
}