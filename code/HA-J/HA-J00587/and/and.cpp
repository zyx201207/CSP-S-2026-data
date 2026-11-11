#include <bits/stdc++.h>

using namespace std;
const int N=2e5+10;
int n,m,mk[N];
bool aa[N][60];
long long a[N],ans,ma;
struct node{
	long long l,k;
}b[N];
void dfs(long long x,int y){
	if(y==m){
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!mk[i]){
			mk[i]=1;
			dfs(x&a[i],y+1);
			mk[i]=0;
		}
	}
}
map <long long,bool> mp;
bool cmp(int x,int y){
	return x>y;
}
bool cmpp(node x,node y){
	return x.k>y.k;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;i++) scanf("%d",&a[i]),ma=max(ma,a[i]);
	if(n<=20||(n<=2000&&m==2)){
		for(int i=1;i<=n;i++){
			mk[i]=1;
			dfs(a[i],1);
			mk[i]=0;
		}
	}else if(m==1){
		ans=ma;
	}else if(m==n){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans&=a[i];
		}
	}else{
		for(int i=0;i<=40;i++){
			long long cnt=pow(2,i);
			mp[cnt]=1;
		}
		bool A=1,B=1;
		if(!mp[n]) B=0;
		for(int i=1;i<=n;i++){
			if(!mp[a[i]+1]) A=0;
			if(a[i]!=i-1) B=0;
		}
		if(A){
			sort(a+1,a+1+n,cmp);
			ans=a[1]&a[2];
			for(int i=3;i<=m;i++) ans&=a[i];
		}else{
			sort(a+1,a+1+n,cmp);
			ans=a[1]&a[2];
			for(int i=3;i<=m;i++) ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
