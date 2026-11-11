#include<bits/stdc++.h>
using namespace std;
int a[200005],g[200005],l[200005];
struct node{
	bool y[35];
}an[200005];
long long cnt=0,n,m;
void dfs(int yx,long long ans,int c){
	if(yx==m) {
		cnt=max(cnt,ans);
		return ;
	}
	if(n-c+yx<m) return ;
	if(yx==0){
		dfs(1,l[c],c+1);
		dfs(0,ans,c+1);
	}
	else {
		dfs(yx+1,l[c]&ans,c+1);
		dfs(yx,ans,c+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxn=0,maxi;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		int k=1;
		cin>>l[i];
		x=l[i];
		if(x>maxn) maxn=x,maxi=i;
		while (x){
			g[i]++;
			an[i].y[k]=x%2;
			a[i]+=x%2;
			k++,x/=2;
		}
	}
	//特殊性质C
	if(n<=29){
		dfs(0,0,0);
		cout<<cnt;
		return 0;
	}
	//特殊性质A
	bool flag=1;
	
	for(int i=1;i<=n;i++){
		if(a[i]!=g[i])  flag=0;	
	} 
	if(flag==1) {
		int ans=1;
		sort(l+1,l+1+n);
		cout<<l[n-m+1];
		return 0;
	}
	//特殊性质B
	flag=1;
	sort(l+1,l+1+n);
	for(int i=1;i<=n-1;i++){
		if(l[i]+1!=l[i+1]) flag=0;
	}
	if(flag==1&&l[1]==0){
		if(m>=n/2) cout<<n-m;
		else cout<<0;
		return 0;
	}
	//特殊性质4
	if(m==1)  {
		sort(l+1,l+1+n);
		cout<<l[n];
		return 0;
	}
	//特殊性质5
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long ans=l[i]&l[j];
				cnt=max(cnt,ans);
			}
		}
		cout<<cnt;
		return 0;
	} 
	//特殊性质6
	if(m==n){
		long long ans=l[1];
		for(int i=1;i<=n;i++){
			ans&=l[i];
		}
		cout<<ans;
		return 0;
	} 
	//特殊性质7
	if(m==n-1){
		long long ans;
		for(int i=1;i<=n;i++){
			if(i==1)ans=l[2];
			else ans=l[i-1];
			for(int j=1;j<=n;j++){
				if(j!=i) ans&=l[j];
			}
			cnt=max(cnt,ans);
		}
		cout<<cnt;
		return 0;
	} 
	//特殊性质8
	sort(l+1,l+1+n);
	long long ans=4;
	if(l[n]<4){
		for(int i=n;i>=n-m+1;i--){
			ans&=l[i];
		}	
		cout<<ans;
		return 0;
	}
	
	return 0;
}
