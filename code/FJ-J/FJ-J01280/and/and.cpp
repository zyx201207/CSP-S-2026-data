#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=2e5;
int n,m,flagA=1,flagB=1,flagC=1;
int a[N+5];
int vis[N+5];
int zmj=-1;
int a1[N+5];
int a2[N+5];
int pp[35];
void dfs(int x,int num,int mm){
	if(num==m){
		zmj=max(zmj,mm);
		return;
	}
	if(vis[x]||x>n)return;
	dfs(x+1,num,mm);
	vis[x]=1;
	dfs(x+1,num+1,(mm&a[x]));
	vis[x]=0;
}
bool cmp(int a,int b){
	return a>b;
}
void hh(){
	pp[0]=1;
	for(int i=1;i<=32;i++){
		pp[i]=pp[i-1]*2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	hh();
	//int cc=n;
	//while((cc&1)==0)cc/=2;
	//if(cc!=1)flagB=0;
	for(int i=1;i<=n;i++){
		int g=a[i]+1,ff=0;
		for(int j=1;j<=32;j++){
			if(g==pp[i]){
				ff=1;
				break;
			}
		}
		if(!ff)flagA=0;
		//if(a[i]!=(i-1)) flagB=0;
		if(a[i]>3)flagC=0;
	}
	if(m==1){
		int mmax=-1;
		for(int i=1;i<=n;i++){
			mmax=max(mmax,a[i]);
		}
		cout<<mmax;
		return 0;
	}
	if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==(n-1)){
		a1[0]=0;a2[0]=0;
		a1[1]=a[1];
		a2[1]=a[n];
		for(int i=2;i<=n;i++)a1[i]=a1[i-1]&a[i];
		for(int i=n-1;i>=1;i--)a2[i]=a2[i+1]&a[i];
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a1[i-1]&a2[i+1]);
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){		
		dfs(1,0,pp[30]-1);
		cout<<zmj;
		return 0;
	}	
	if(flagA){
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	//if(flagB){
		
	//}
	if(flagC){
		int s1=0,s2=0,s3=0,s0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)s0++;
			if(a[i]==1)s1++;
			if(a[i]==2)s2++;
			if(a[i]==3)s3++;
		}
		if(s3>=m){
			cout<<3;
			return 0;
		}
		else if((s3+s2)>=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
