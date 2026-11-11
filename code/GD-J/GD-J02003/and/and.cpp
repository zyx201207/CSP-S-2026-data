#include<bits/stdc++.h>
using namespace std;
int m,n,a[200008],ans,s=pow(2,30)-1,k=1,u,f[5],f2[289];
void dfs(int st,int an,int in){
	if(st>m){
		cout<<an<<' '<<ans<<endl;
		ans=max(ans,an);
		return;
	}for(int i=in+1;i<=n;i++){
		dfs(st+1,(an&a[in]),i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		u=max(u,a[i]);
		if(a[i]!=i-1)
			k=0;
		//s=(s&a[i]);
	}if(n<=20){
		for(int i=1;i<=n-m;i++)
			dfs(i,s,i);
		cout<<ans;
		return 0;
	}
	if(u<=4){
		for(int i=1;i<=n;i++)
			f[a[i]]++;
		if(f[4]>=m)
			cout<<4;
		else if(f[2]+f[3]>=m){
			cout<<2;
		}else if(f[2]+f[3]<m and f[1]>=m)
			cout<<1;
		else
			cout<<0;
		return 0; 
	}
	if(k){
		if(n==m)
			cout<<0;
		else{
			sort(a+1,a+1+n);
			if(m==1)
				cout<<a[n];
			else{
				for(int i=n;i>=n-m+1;i--)
					s=(s&a[i]);
				cout<<s;
				return 0;
			}
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}cout<<ans;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,(a[i]&a[j]));
				}
			}
		}cout<<ans;
		return 0;
	}if(m==n-1){
		sort(a+1,a+1+n);
		for(int i=n;i>1;i--){
			s=(s&a[i]);
		}cout<<s;
		return 0;
	}if(m==n){
		for(int i=1;i<=n;i++){
			s=(s&a[i]);
		}cout<<s;
		return 0;
	}sort(a+1,a+1+n);
	for(int i=n;i>=n-m+1;i--){
		s=(s&a[i]);
	}cout<<s;
	//return 0;
	return 0;
}
