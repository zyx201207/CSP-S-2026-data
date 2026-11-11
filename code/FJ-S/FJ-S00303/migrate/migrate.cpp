#include<bits/stdc++.h>
using namespace std;
int c,T,n,q,p,k[20005],dd;
long long d,a[20005];
void dfs(int s,int t,int l){
	if(l>dd/2+1) return;
	if(s==t){
	    q=min(q,l);
	    k[l]++;
		return;	
	} 
	for(int i=s+1;i<=t;i++){
		if(a[i]-a[s]>d) break;
		else dfs(i,t,l+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				q=1e5;
				dd=a[j]-a[i];
				dfs(i,j,0);
				if(k[q]==2) ans++;
			    for(int i=1;i<=301;i++) k[i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

