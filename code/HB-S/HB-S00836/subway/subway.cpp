#include<bits/stdc++.h>
using namespace std;
freopen("subway.in","r","std.in");
freopen("subway.out","w","std.out");
long long a[100005];
int main(){
int n,s=0;
cin>>n;
int c,m,n,d,p;
cin<<c<<m<<d<<p;
for (int i=0 ; i < n ;i++){
    cin>>a[i];
}
s=c+m+d+p;
cout<<s;
cout<<s+p;
}
