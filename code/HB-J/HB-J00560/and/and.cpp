#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,t,a[MAXN],kl,ans[MAXN],maxn=-0x3f3f3f;
int book[MAXN];
void dfs(int num,int idx){
	if(num==idx+1){
		maxn=ans[1];
		for(int i=2;i<=idx;i++){
			maxn=(maxn&ans[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			kl++;
			ans[kl]=a[i];
			book[i]=1;
			dfs(num+1,idx);
			book[i]=0;
			kl--;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>t;
	if(t==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(t==n){
		cin>>a[1];
		maxn=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			maxn=(maxn&a[i]);
		}
		cout<<maxn;
	}
	else if(t==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,t);
		cout<<maxn;
	}
	return 0;
}
