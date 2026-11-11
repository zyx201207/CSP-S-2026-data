#include <bits/stdc++.h>
using namespace std;

long long MAXN=(long long)(2e30)+10;
long long a[200005];
int n,m,ans=0;

long long maxen(long long a,long long b){
	return (a>b?a:b);
}

void Fusion(int x,int cnt,long long sum){
	if(n-cnt+1<m)return ;
	if(cnt==m){
		ans=maxen(ans,(sum&a[x]));
		//cout << "ans:" << ans << "  sum: " << sum << "  x: " << x << "\n";
		return ;
	}
	for(int i=x;i<=n /*(n-m+cnt)*/;i++){
		
		Fusion(i+1,cnt+1,sum&a[i]);
		
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=(n-m+1);i++){
		Fusion(i,1,a[i]);
	}
	cout << ans;
	return 0;
} 
