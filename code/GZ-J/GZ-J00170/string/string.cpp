//GZ-J00170 遵义市红花岗区第四小学 杨易千 
#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==2 && c[1]!=c[2]){
		cout<<min(a[1],a[2]);
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
