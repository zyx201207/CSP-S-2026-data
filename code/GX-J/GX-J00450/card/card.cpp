#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e9+5;
int a[N];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
cin>>a[i];
}
for(int i=0;i<m;i++){
	cout<<a[i];
}
return 0;
}
