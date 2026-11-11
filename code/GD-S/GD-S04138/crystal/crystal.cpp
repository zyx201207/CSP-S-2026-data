#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=500010;
int n,ans;
ll a[N];
ull pre[N],front[N],m;
ull calc(int start,int end){
	return pre[end]-pre[start]-(start-1)*(front[end]-front[start]);
}
int find(int x){
	int left=1,right=x,tmp=0;
	while(left<right){
//		cout<<left<<" "<<right<<endl;
		int mid=(left+right)/2;
		if(calc(mid,x)>m){
			left=mid+1;
		}else{
			right=mid;
		}
	}
	return x-left;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%ulld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
		front[i]=front[i-1]+a[i]-a[i-1];
//		cout<<pre[i]<<" ";
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<front[i]<<" ";
//	}cout<<endl;
	for(int i=1;i<=n;i++){
//		cout<<i<<":";
		int c=find(i);
		ans=max(c+1,ans);
	}
	printf("%d",ans);
	return 0;
}
