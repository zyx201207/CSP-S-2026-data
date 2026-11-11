//GZ-J00170 遵义市红花岗区第四小学 杨易千 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,greater<long long>());
		cout<<a[1];
		return 0;
	}
	
	return 0;
}
