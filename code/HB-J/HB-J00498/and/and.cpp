#include <bits/stdc++.h>
using namespace std;
int a[200009];
int maxs=-1;
int n,m;
void dfs(int p,int l,int ans){
	if(p>m){
		maxs=max(maxs,ans);
		return ;
	}
	for(int i=l+1;i<=n;i++){
		dfs(p+1,i,ans&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	feropen("and.out","w",stdout);
	cin>>n>>m;
	int A=1,f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]+1&&i!=1) f=0;
		if(a[i]>=4) A=0;
	}
	if(n<=20){
		int t=0;
		for(int i=0;i<=20;i++){
			t+=pow(2,i);
		}
		dfs(1,0,t);
		cout<<maxs;
		return 0;
	}
	else if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			int ans=0;
			for(int i=0;i<=20;i++){
				ans+=pow(2,i);
			}
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=ans&a[j];
			}
			mx=max(mx,ans);
		}
		cout<<mx;
		return 0;
	}
	else if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}else if(m==2){
		int mx=-1;
		for(int i=1;i<=n;i++){
			int ans=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=a[i]&a[j];
			}
			mx=max(mx,ans);
		}
		cout<<mx;
		return 0;
	}else if(A==1){
		int m_0=0,m_1=0,m_2=0,m_3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) m_0++;
			if(a[i]==1) m_1++;
			if(a[i]==2) m_2++;
			if(a[i]==3) m_3++;
		}
		if(m_3>=m){
			cout<<3;
			return 0;
		}else{
			m-=m_3;
			if(m_2>=m){
				cout<<2;
				return 0;
			}else if(m_1>=m){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
	}
	else if(f==1){
		sort(a+1,a+1+n);
		int ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else{
		sort(a+1,a+1+n);
		int ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
