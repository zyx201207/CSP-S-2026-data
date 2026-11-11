#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],c[200010];
long long Max=0;
void dfs(int deep,int x){
	b[deep]=a[x];
	if(deep==n){
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
//		}
//		cout<<endl;
		long long sum=b[1];
		for(int i=2;i<=m;i++){
			sum=sum&b[i];
		}
		Max=max(Max,sum);
		return;
	}
	c[x]=1;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
//			cout<<1<<" "<<deep+1<<" "<<i<<endl;
			dfs(deep+1,i);
		}//else cout<<0<<endl;
	}
	c[x]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0);
//	do{
//		long long sum=a[1];
//		for(int i=2;i<=m;i++){
//			sum=sum&a[i];
//		}
//		Max=max(Max,sum);
//	}while(next_permutation(a+1,a+n+1));
	cout<<Max;
	return 0;
}
