#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],p[N],ans=-1e9,maxn=-1e9,ismn,cnt[35],pw[35],vis[N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int c,int yx){
	if(yx==m){
		int tmp=p[1];
		for(int i=2;i<=m;i++){
			tmp&=p[i];
		}
		if(tmp>ans){
			ans=tmp;
		}
		return;
	}
	if(c>n){
		return;
	}
	dfs(c+1,yx);
	p[yx+1]=a[c];
	dfs(c+1,yx+1);
	p[yx+1]=0;
	return;
} 
int main(){
//	freopen("and5.in","r",stdin);
//	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=33;i++){
		pw[i]=pw[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmp=a[i];
		int ii=0;
		while(tmp){
			cnt[ii]+=tmp&1;
			tmp>>=1;
			ii++;
		}
		maxn=max(a[i],maxn);
		if(i==1){
			ismn=a[i];
		}
		else{
			ismn&=a[i];
		}
	}
	if(n<=20&&m<=n){
		dfs(1,0);
		cout<<ans;
	}
	else if(n<=2000&&m==1){
		cout<<maxn;
	}
	else if(n<=2000&&m==n){
		cout<<ismn;
	}
	else{
		int pos=0;
		bool f=1;
		for(int i=32;i>=0;i--){
			if(cnt[i]>=m){
				f=0;
				pos=i;
				break;
			} 
		}
		if(f){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			a[i]&=pw[pos+1]-1;
		}
		sort(a+1,a+1+n,cmp);
//		int ii;
//		for(ii=1;ii<=n;ii++){
//			if(a[ii]<=pw[pos+1]-1){
//				break;
//			}
//		}
		ans=a[1];
		for(int i=2;i<=m;i++){
//			ii++;
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}

