#include <bits/stdc++.h>
using namespace std;
long long shu[1000000],mx,n,xuan;
void dfs(int dq,int xz,int sum){
	if (xz>xuan){
		return ;
	}
	if (xz==xuan){
		if (mx<sum){
			mx=sum;
		}
		return ;
	}
	for (long long i=dq;i<=n;i++){
		if (sum==0){
			sum+=shu[i];
		}else {
			sum=sum&shu[i];
			cout<<sum<<endl;
		}
		dfs(i+1,xz+1,sum);
	}
}
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	long long i;
	cin>>n>>xuan;
	for (i=1;i<=n;i++){
		cin>>shu[i];
	}
	mx=0;
	dfs(1,0,0);
	cout<<mx;
	return 0;
}
