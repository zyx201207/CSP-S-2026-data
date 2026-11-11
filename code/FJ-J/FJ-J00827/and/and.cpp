#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],l[30],ans=0,sum;
bool f[30];
void dfs(int x,int w){
	if(x>m){
		sum=a[l[1]];
		for(int i=2;i<=m;i++){
			sum=(sum&a[l[i]]);
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=w+1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			l[x]=i;
			dfs(x+1,i);
			f[i]=0;
		}	
	}
}
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout << ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout << ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout <<ans;
	}else{
		dfs(1,0);
		cout << ans;	
	}
	
	return 0;
}
