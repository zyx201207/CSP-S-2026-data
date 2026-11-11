#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll er[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
ll a[2005];
ll n,m;
ll maxa=0;
ll ans; 
struct ejz{
	int idx,num;
} b[2005];
void dfs(int i,int c,long long zhi){
	if(c==m){
		ans=max(ans,zhi);
		return ;
	}else if(i>n)return ;
	if(n-i>=m-c)dfs(i+1,c,zhi);
	dfs(i+1,c+1,zhi&a[i]);
	return ;
}
void cifa(){
	int ln=n;
	ans=a[n];
	for(int i=1;i<m;i++){
		ans=ans&a[n-i];
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxa=max(maxa,a[i]);
	}
	if(n<=20||m==2){
		dfs(1,0,INT_MAX);
		dfs(1,0,a[1]);
	}else if(n<=2000&&m==1){
		ans=maxa;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}else{
		sort(a+1,a+n+1);
		bool ifa=1;
		for(int i=1;i<=n;i++){
			bool dsa=0;
			for(int j=0;j<=20;j++){
				if(a[i]==er[j]-1){
					dsa=1;
					break;
				}
			}
			if(!dsa){
				ifa=0;
				break;
			}
		}
		if(ifa){
			cifa();
		}else{
			for(int i=1;i<=n;i++){
				long long ls,cnt=0;
				ls=a[i];
				while(ls){
					if(ls%2!=0)cnt++;
					ls/=2;
				}
				b[i].idx=i;
				b[i].num=cnt;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

