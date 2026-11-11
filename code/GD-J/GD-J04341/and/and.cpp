#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int n,m,ans,a[N],v[N];
void dfs(int x,int sum){
	cout<<x<<" "<<sum<<"\n";
	if(sum<=ans)return;
	if(x>=m)ans=max(ans,sum);
	else{
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				v[i]=1;
				dfs(x+1,(sum&a[i]));
				v[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans;
	}else if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}else{
		if(n>2026){
			sort(a+1,a+1+n,greater<int>());
			ans=a[1];
			for(int i=2;i<=m;i++){
				ans=(ans&a[i]);
			}
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=n;i++){
			v[i]=1;
			dfs(1,a[i]);
			v[i]=0;
			cout<<"\n";
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
