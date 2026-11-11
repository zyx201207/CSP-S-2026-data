#include <bits/stdc++.h>
using namespace std;
int c,T;
long long n,d,a[2000010];
int b[2000010],cnt;
int dfs(long long k){
	int ans;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=k){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int bfs(long long k){
	int ans;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>=k){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int f=0;
				int t=0;
				long long k=a[i];
				int s=1;
				while(k<a[j]&&s<j){
					k+=d;
					s=dfs(k);
					k=a[s];
					if(a[s+1]-a[s]>d&&a[s+1]<=a[j]){
						f=1;
						break;
					}
					if(k<a[j])b[++t]=s;
				}
				if(f==1)continue;
				if(t==1){
					int o=bfs(a[j]-d);
					if(o==b[1]-1)cnt++;
				}
				else{
					int o=bfs(a[j]-d);
					if(o==b[t]-1){
						int oo=bfs(a[o]-d);
						if(oo==b[t-1]){
							cnt++;
						}
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
}
