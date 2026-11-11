#include<bits/stdc++.h>
using namespace std;
long long m,n,i,k,a[100000000];
int cmp(int a,int b){
	return a>b;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;	
for(i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n+1,cmp);

cout<<a[m-1];
	return 0;
}
