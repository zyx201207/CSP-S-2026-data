#include<bits/stdc++.h>
using namespace std;
int a1=INT_MAX;
long long n,m,a[200005],b[200005];

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i]|! a1;
}
cout<<b[1];
sort(b+1,b+n+1);

return 0;
}


