#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2*1e6+10;
int c,t,n;
ll d,x[N],cs,ch,ans;
void solve(int a,int b){
	if(a==b){
		if(ans==cs)ch++;
		else{
			ans = min(ans,cs);
			ch = 1;
		}
		return ;
	}
	for(int i = b;i>=a;i--){
		if(x[i]-x[a]<=d){
			cs++;
			solve(i,b);
			cs--;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d",&n);
		scanf("%lld",&d);
		for(int i = 1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		ll zz = 0;
		for(int i = 1;i<n;i++){
			for(int j = i+1;j<=n;j++){
				cs = 0;
				ch = 1;
				ans = N;
				solve(i,j);
				if(ch==2)zz++;
			}
		}
		printf("%lld\n",zz);
	}
	return 0;
}
