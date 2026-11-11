#include<iostream>
#include<deque>
#include<algorithm>
#include<math.h>
using namespace std;
int n,m;
long long a[200005];
long long ans=0;
void dfs(long long sum,int k,int c){
	if(k>n)return ;
	if(c==m){
		if(sum>ans)ans=sum;
		return ;
	}
	dfs(sum&a[k],k+1,c+1);
	dfs(sum,k+1,c);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	int maxn=0;bool isSqrt=true;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if((int)(sqrt(a[i]))*(int)(sqrt(a[i]))-1!=a[i]){
			isSqrt=false;
		}
		maxn=max((long long)maxn,a[i]);
	}
	if(isSqrt){
		sort(a,a+n);
		cout<<a[m-n-1];
	}
	dfs((1<<50)-1,0,0);
	printf("%lld",ans);
	return 0;
}
