#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],ans=-1;
bool bk[N],flag=0;
void dfs(long long cnt,long long dep,long long ans1,long long n1){
	if(cnt>m) return ;
	if(cnt!=0 && cnt==m)ans=max(ans,ans1);
	for(long long i=n1+1;i<=n;i++){
		dfs(cnt+1,dep+1,ans1&a[i],i);
		dfs(cnt,dep+1,ans1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4) flag=1;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(n<=20){
		dfs(0,0,9223372036854775807,0);
		cout<<ans;
		return 0;
	}else if(flag==0){
		long long a1=0,a2=0,a3=0,a4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) a1++;
			else if(a[i]==1) a2++;
			else if(a[i]==2) a3++;
			else if(a[i]==3) a4++;
			if(a4>=m) cout<<3;
			else if(a4+a3>=m) cout<<2;
			else if(a4+a2>=m) cout<<1;
			else cout<<0;
			return 0;
		}
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}

	return 0;	
}	


