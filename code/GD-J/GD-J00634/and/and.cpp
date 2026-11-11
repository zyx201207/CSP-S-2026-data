#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
int a[200010],used[200010],b[200010];
void dfs(int pos,int ans,int x){
	if(pos==m){
		maxn=max(maxn,ans);
		return; 
	}
	for(int i=x+1;i<=n;i++){
		if(used[i]==0){
			b[pos+1]=a[i];
			used[i]=1;
			dfs(pos+1,(ans&a[i]),i);
			used[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		for(int i=1;i<=n;i++){
			used[i]=1;
			b[1]=a[i];
			dfs(1,a[i],1);
			used[i]=0;
		}
		cout<<maxn;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				maxn=max(maxn,a[i]);
			}
			cout<<maxn;
			return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxn=max(maxn,(a[i]&a[j]));
				}
			}
			cout<<maxn;
			return 0;
		}
		if(m==n){
			maxn=a[1];
			for(int i=1;i<=n;i++){
				maxn=(maxn&a[i]);
			}
			cout<<maxn;
			return 0;
		}
	}
	bool A=1;
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=1;pow(2,j-1)<=a[i];j++){
			if(pow(2,j)-1==a[i]){
				num=1;
				break;
			}
		}
		if(num==0) break;
	}
	if(A==1){
		sort(a+1,a+1+n);
		maxn=a[n];
		for(int i=n;i>=n-m+1;i--){
			maxn=(maxn&a[i]);
		}
		cout<<maxn;
		return 0;
	}
	maxn=a[n];
	for(int i=n;i>=1;i/=2){
		maxn=(maxn&a[i]);
	}
	cout<<maxn;
	return 0;
}
