#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans;
ll m,a[N],s[N];
bool calc(int i,int j){
	return (a[j]*(j-i+1)-(s[j]-s[i-1]))<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n&&calc(i,j))j++;
		ans=max(ans,j-i);
	}
	printf("%d\n",ans);
} 
