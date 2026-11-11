#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,maxa,ans,b[200005];
void dfs(long long st,long long lst){
	if(st>m){
		long long sum=b[1];
//		cout<<b[1]<<" ";
		for(int i=2;i<=m;i++){
			sum=sum&b[i];
//			cout<<b[i]<<" ";
		}
		ans=max(ans,sum);
//		cout<<sum<<endl;
		return ;
	}
	for(int i=lst+1;i<=n;i++){
		if(st==1){
			b[st]=a[i];
			dfs(st+1,i);
		}else{
			b[st]=a[i];
			dfs(st+1,i);
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else{
		dfs(1,0);
		cout<<ans;
	}
	
	return 0;
}
