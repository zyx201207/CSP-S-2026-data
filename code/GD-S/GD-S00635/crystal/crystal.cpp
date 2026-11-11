#include<bits/stdc++.h>
using namespace std;
long long a[500005]={};
long long b[500005]={};
int x(int i,int j){
	return (j-i+1)*a[j]-(b[j]-b[i-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	if(a[1]<0){
//		long long p=abs(a[1]);
//		for(int i=1;i<=n;++i){
//			a[i]+=p;
////			cout<<a[i]<<" ";
//		}
////		cout<<endl;
//	}
	for(int i=1;i<=n;++i){
		b[i]=b[i-1]+a[i];
	}
	long long maxn=0,num=0;
	long long int i=1,j=2;
	for(;i<=n,j<=n;){
		num=x(i,j);
		if(num<=m){
			maxn=max(maxn,j-i+1);
			j++;
		}else{
			i++;
		}
//		cout<<num<<" "<<i<<" "<<j<<" "<<maxn<<endl;
	}
	cout<<maxn;
}
