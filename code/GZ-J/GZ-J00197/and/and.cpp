//GZ-J00197   遵义市第四中学	代铭轩 
#include <bits/stdc++.h>
using namespace std;
const int maxn=200110;
long long a[maxn];
long long b[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	//有n 个非负整数
	//从这 n个数中选出m 个，使得选出的 m 个数的二 进 制 按 位 与 值最大。
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i-1]&a[i];
		ans=max(ans,b[i]);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

