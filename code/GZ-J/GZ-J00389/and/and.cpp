#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],sum=0;
bool com(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,com);
	sum=a[0];
	for(int i=1;i<m;i++) sum=(sum&a[i]);
	cout<<sum;
	return 0;
}
