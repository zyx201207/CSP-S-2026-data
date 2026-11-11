#include<bits/stdc++.h>
using namespace std;
long long c,n,t,d,a[2000010];
long long dfs(int m,int cnt,int l,int r){
	if(cnt==m){
		if(l==r){
			return 1;
		}
		else{
			return 0;
		}
	}
	long long res=0;
	long long i=1;
	while(a[l+i]-a[l]<=d){
		res+=dfs(m,cnt+1,l+i,r);
		i++;
	}
	return res;
}
bool check(long long l,long long r){
	long long m=0,i=l;
	while(i<r&&a[i+1]-a[i]<=d){
		int times=1;
		if(a[i+times]-a[i]<=d){
			while(a[i+(times+1)]-a[i]<=d){
				times++;
			}
		}
		i+=times;
		m++;
	}
	if(m==0){
		return false;
	}
	if(dfs(m,0,l,r)==2){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
