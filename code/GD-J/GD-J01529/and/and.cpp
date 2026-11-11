#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,inf=4e18,big=(1<<25);
int n,m,Mx=-inf,Mn=inf,fA=1,fB=1,fC=1,ans=0,sum=inf,vis[30],a[N];
map<int,int> mp;
bool ck(int x){
	int p=x+1;
	for(int i=0;i<=25;i++){
		int z=(2<<i);
		if(z==p)return 1;
	}
	return 0;
}
void ckx(int x){
	int p=x,res=inf,cnt=0;
	for(int i=1;x>0;i++){
		if(x&1){
			cnt++;
			if(res==inf)res=a[i];
			else res&=a[i];
		}
		x>>=1;
	}
	if(cnt==m)ans=max(ans,res);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(sum==inf)sum=a[i];
		else sum&=a[i];
		
		if(!ck(a[i]))fA=0;
		if(a[i]!=i-1)fB=0;
		if(a[i]>=4)fC=0;
		
		mp[a[i]]++;
		Mx=max(Mx,a[i]);
		Mn=min(Mn,a[i]);
	}
	if(fC){
		for(int i=3;i>=0;i--){
			if(m-mp[i]>0)m-=mp[i];
			else{
				cout<<i;
				return 0;
			}
		}
	}
	else if(n<=20){
		for(int i=0;i<(1<<n);i++)ckx(i);
		cout<<ans;
	}
	else if(n>2000&&n<=200000){
		if(fA){
			sort(a+1,a+n+1);
			cout<<a[n-m];
		}
		else if(fB){
			int res=a[n];
			for(int i=n-1;i>=n-m+1;i--)res&=a[i];
			cout<<res;
		}
		else cout<<0;
	}
	else{
		if(m==1)cout<<Mx;
		else if(m==n)cout<<sum;
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(j!=i)ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
		}
	}
	return 0;
} 
