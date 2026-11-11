#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
struct node{
	int num_of_one;
	long long num;
}arr[N];
bool cmp(node a,node b){
	if(a.num_of_one==b.num_of_one)return a.num>b.num;
	return a.num_of_one>b.num_of_one;
}
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&arr[i].num);
		long long k=arr[i].num;
		while(k){
			if(k%2)++arr[i].num_of_one;
			k=k>>1;
		}
	}
	sort(arr+1,arr+1+n,cmp); 
	ans=arr[1].num;
	for(int i=2;i<=m;++i){
		ans&=arr[i].num;
	}
	printf("%lld",ans);
	return 0;
}
