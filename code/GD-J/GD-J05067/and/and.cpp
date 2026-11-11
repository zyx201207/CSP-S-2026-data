#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200007],maxx=-1,mx=-1,cnt;
void dfs(long long c,long long sum,long long num){
	if(num==m){
		maxx=max(maxx,sum);
		return ;
	}
	if(c==n+1){
		return ;
	}
	if(num==0){
		dfs(c+1,a[c],num+1);
	    dfs(c+1,0,num);
	}else{
		dfs(c+1,sum&a[c],num+1);
	    dfs(c+1,sum,num);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
		if(a[i]==1){
			cnt=a[i];
		}else{
			cnt=cnt&a[i];
		}
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<maxx;
	}else{
		if(m==1){
			cout<<mx;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					long long ans=a[i]&a[j];
					maxx=max(maxx,ans);
				}
			}
			cout<<maxx;
		}else if(m==n){
			cout<<cnt;
		}else if(mx<4){
			cout<<3;
		}else if(a[1]==0){
			cout<<n-1;
		}else{
			cout<<mx;
		}
	}
	return 0;
}

