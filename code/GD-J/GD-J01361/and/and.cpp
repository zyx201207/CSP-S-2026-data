#include<bits/stdc++.h>
#define int long long
int a[200005],ans,n,m;
bool vis[200005];
int cnt[200005];
std::vector<int> vs[50];
void dfs(int c,int val){
	if(c==m+1){
		ans=std::max(ans,val);
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==true)continue;
			else{
				vis[i]=true;
//				printf("%lld&%lld=%lld\n",val,a[i],val&a[i]);
				if(val!=-1)dfs(c+1,(val&a[i]));
				else dfs(c+1,a[i]);
				vis[i]=false;
			}
		}
	}
	return;
}
signed main(){
	std::freopen("and.in","r",stdin);
	std::freopen("and.out","w",stdout);
	int mx=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=std::max(mx,a[i]);
	}
	if(m==1){
		printf("%lld",mx);
		return 0;
	}else if(m==2){
		int mmx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				mmx=std::max(mmx,(a[i]&a[j])); 
			} 
		}
		printf("%lld",mmx); 
		return 0;
	}else if(m==n){
		int sand=a[1];
		for(int i=2;i<=n;i++)sand&=a[i];
		printf("%lld",sand);
		return 0;
	}else if(m==n-1){
		int mmx=0;
		for(int i=1;i<=n;i++){
			int mx=(1<<30)-1;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				mx&=a[j]; 
			} 
			mmx=std::max(mmx,mx);
		}
		printf("%lld",mmx); 
		return 0;
	}else if(mx<4){
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		int a=cnt[3],b=cnt[2],c=cnt[1],d=cnt[0];
		if(a>=m){
			printf("3");
		}else if((a+b)>=m){
			printf("2");
		}else if((a+b+c)>=m){
			printf("1");
		}else{
			printf("0");
		}
		return 0;
	}else{
		dfs(1,-1);
		printf("%lld\n",ans);
	}
	
	return 0;
}
