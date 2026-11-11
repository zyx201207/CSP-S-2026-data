#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200006],zans=0,e,rcnt;
long long dfs(long long s,long long cnt,long long ans){
//	cout<<s<<" "<<e<<" "<<cnt<<" "<<ans<<" "<<rcnt<<endl;
	if(s==e){
		if(cnt==ans){
			rcnt+1;
		} 
		return cnt; 
	}
	for(int i=1;i<=n;i++){
		if(s+m>=a[i]&&s<a[i]&&a[i]<=e) dfs(a[i],cnt+1,ans); 
	}
	
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(long long k=2;k<=n;k++){
		long long ans=0,z=1;
		if(k==1) ans=1;
		while(z<k){
			for(int i=k;i>=1;i--){
				if(a[z]+m>=a[i]){
					z=a[i];
					ans++;
					break;
				}
			}
			
		}
		e=a[k];
		long long rcnt=0;
		int cnt=dfs(a[1],0,ans);
		cout<<endl;
		cout<<rcnt<<" ";
		
	}
	return 0;
}
