#include<iostream> 
#include<string> 
#include<cstdio> 
#include<algorithm> 
#define int long long
using namespace std;

int a[200005],f[200005],n,m,ans=0,mx=0,s1[200005],s2[200005];
void dfs(int u,int cnt){
	if(cnt>m)return;
	if(u>n){
		if(cnt!=m)return;
		int res=mx;
		for(int i=1;i<=n;i++){
			if(f[i])res=(res&a[i]);
		}
		ans=max(ans,res);
		return;
	}
	f[u]=0;
	dfs(u+1,cnt);
	f[u]=1;
	dfs(u+1,cnt+1);
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int A=1,B=1,C=1,c1=0,c2=0,c3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		int t=a[i];
		while(t){
			int r=t%2;
			if(r==0)A=0;
			t/=2;
		}
		if(a[i]!=i-1)B=0;
		if(a[i]>=4)C=0;
		if(a[i]==3)c3++;
		else if(a[i]==2)c2++;
		else if(a[i]==1)c1++;
	}
	s1[1]=a[1],s2[n]=a[n];
	for(int i=2;i<=n;i++)s1[i]=(s1[i-1]&a[i]);
	for(int i=n-1;i>=1;i--)s2[i]=(s2[i+1]&a[i]);
	if(n<=20){
		dfs(1,0);
		cout<<ans<<endl;
		return 0;
	}
	if(m==n){
		cout<<s1[n]<<endl;
		return 0;
	}
	if(m==1){
		cout<<mx<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1){
		ans=max(s1[n-1],s2[2]);
		for(int i=2;i<n;i++){
			ans=max(ans,s1[i-1]&s2[i+1]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(A){
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans=(ans&a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(C){
		if(c3>=m)ans=3;
		else if(c3+c2>=m)ans=2;
		else if(c3+c1>=m)ans=1;
		else ans=0;
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
}


