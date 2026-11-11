#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long q[200005],h[200005];
long long dfs(int i,int k,long long ans){
	if(k==0) return ans;
	if(i>n) return -1;
	return max(dfs(i+1,k-1,ans&a[i]),dfs(i+1,k,ans));
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	} 
	if(m==1){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}	
		cout<<mx;
		return 0;
	}if(m==n){
		long long ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}	
		cout<<ans;
		return 0;
	}
	if(n<=20){
		cout<<dfs(1,m,(1<<21)-1);
		return 0;
	}
	if(m==2&&n<=10000){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue; 
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		q[1]=a[1];
		for(int i=2;i<=n;i++){
			q[i]=q[i-1]&a[i];	
		}
		h[n]=a[n];
		for(int i=n-1;i>=1;i--){
			h[i]=h[i-1]&a[i];
		}
		long long mx=h[2];
		for(int i=2;i<n;i++){
			mx=max(mx,q[i-1]&h[i+1]);
		}
		cout<<max(mx,q[n-1]);
		return 0; 
	}
	bool V=1; 
	for(int i=1;i<=n;i++){
		int k=1;
		while(((1<<(i*k))-1)<a[i]) k++;
		if(((1<<(i*k))-1)!=a[i]){
			V=0;
			break;
		}
	}
	if(V){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	cout<<0;
	return 0;
}

