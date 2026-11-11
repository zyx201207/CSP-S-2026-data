#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[100005];
int n=0,m=0,js=0,ant=0;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a+0,a+n);
int sum=a[n/2];
for(int i=0;i<n/2;i++){
	 ant+=a[i];
}
int l=(ant+m)/a[n/2];
for(int i=0;i<n;i++){
if(a[i]==a[n/2]){
	js++;
}
}
cout<<l+js;
	return 0;
}

