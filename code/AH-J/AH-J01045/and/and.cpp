#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans;
bool l=1;
void dfs(int j,int g,long long shu){
	if(g==0){
		ans=max(ans,shu);
		return;
	}
	if(j>n){
		return;
	}
	dfs(j+1,g,shu);
	if(shu==0){
		shu=a[j];
		dfs(j+1,g-1,shu);
	}else{
		dfs(j+1,g-1,(shu&a[j]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxnn=-1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		long long t=a[i]+1;
		maxnn=max(maxnn,a[i]);
		while(t%2==0){
			t=t/2;
		}
		if(t!=1){
			l=0;
		}
	}
	if(n<=20){
		dfs(1,m,0);
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		long long maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=(maxn&a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(maxnn<4){
		sort(a+1,a+1+n);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3){
				m--;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==2){
				cnt2++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt1++;
			}
		}
		if(m<=0){
			cout<<3;
			return 0;
		}
		if(cnt2>=m){
			cout<<2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(l==1){
		sort(a+1,a+1+n);
		cout<<a[m];
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
