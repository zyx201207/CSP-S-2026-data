//GZ-J00706 遵义市第十二中学 张明韬
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n+1-1];
		return 0;
	}
	ans=a[n]&a[n-1];
	for(int i=2;i<=m;i++){
		ans=ans&a[n-i+1];
	}
	cout<<ans;
	return 0;
} 
