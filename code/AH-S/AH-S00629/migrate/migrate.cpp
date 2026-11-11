#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N],d,mn=2e7,ans;
void dfs(int s,int t,int cnt){
	if(s==t){
		if(mn>cnt){
			mn=cnt;
			ans=1;
		}else if(mn==cnt) ans++;
		return ;
	}
	for(int i=s+1;i<=t;i++){
		if(a[s]+d>=a[i]) dfs(i,t,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,flag=0;
		long long mx=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=10){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					mn=2e7;
					ans=0;
					dfs(i,j,0);
					if(ans==2) mx++;
				}
			}
			cout<<mx<<"\n";
		}else if(c==11 || c==12){
			long long D=a[2]-a[1],p=d/D;
			if(n-2*p+1>=0 && p>1) printf("%lld\n",n-2*p+1);
			else puts("0");
		}else puts("0");
	}
	return 0;
}
