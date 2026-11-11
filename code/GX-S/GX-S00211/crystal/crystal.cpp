#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN],b[MAXN];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
long long n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}

int cnt=0;
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
    b[a[i]]++;
}

long long mid=n/2+1;
for(int i=1;i<mid;i++){
cnt++;
}
if(b[a[mid]]>=2){
    cnt+=b[a[mid]]-1;
}
    cout<<cnt;



return 0;
}
