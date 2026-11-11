#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[10001];
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a,a+n+1);
	cout<<a[m];
return 0;
}
