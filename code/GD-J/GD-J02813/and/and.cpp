#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mx=0,and_=pow(2,30);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx)mx=a[i]
		and_=and_&a[i];
	}
	if(m==n){
		cout<<and_;
	}
	else cout<<mx;
	return 0;
}
