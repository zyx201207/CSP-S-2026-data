#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void dfs(long long x,long long la,long long pl){
	if(x==0){
		ans=max(ans,la);
		return;
	}
	for(int i=pl+1;i<=n;i++){
		dfs(x-1,la&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(m==1){
		long long o,mo=0;
		for(long long i=1;i<=n;i++){
			cin >> o;
			mo=max(mo,o);
		}
		cout << mo;
	}else if(m==n){
		long long o,mo;
		cin >> o;
		mo=o;
		for(long long i=2;i<=n;i++){
			cin >> o;
			mo=(mo&o);
		}
		cout << mo;
	}else if(m==2){
		for(long long i=1;i<=n;i++){
			cin >> a[i]; 
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			} 
		}
		cout << ans;
	}else if(n<=20){
		for(long long i=1;i<=n;i++){
			cin >> a[i]; 
		}
		for(long long i=1;i<=n;i++){
			dfs(m-1,a[i],i);
		}
		cout << ans;
	}else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
