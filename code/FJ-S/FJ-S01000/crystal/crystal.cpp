#include<bits/stdc++.h>
using namespace std;
long long n,m,num[500010],dp[10010][10010];
long long maxx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f1=true,f2=true;
	long long q;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(!(num[i]==i))f1=false;
		if(i==2){
			q=num[i]-num[i-1];
		}else if(i>2){
			if(num[i]-num[i-1]!=q){
				f2=false;
			}
		}
	}sort(num+1,num+1+n);
	if(n>5000){
		//特殊性质A
		if(f1){
			int sum=0,ans=1,tot=1;
			while(sum<=m&&ans<n){
				sum+=tot;
				//if(sum>m)break;
				tot++;
				ans++;
				if(ans==m)break;
			}cout<<ans; 
			return 0;
		}
		//特殊性质B
		else if(f2){
			int sum=0,ans=1,tot=q;
			while(sum<=m&&ans<n){
				sum+=tot;
				//if(sum>m)break;
				tot+=q;
				ans++;
				if(ans==m)break;
			}cout<<ans; 
			return 0;
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=num[i]-num[j];
		}
	}for(int i=1;i<=n;i++){
		long long sum=0,mk=m;
		for(int j=i;j>=1;j--){
			if(mk-dp[i][j]>=0){
				mk-=dp[i][j];
				sum++;
			}else break;
		}maxx=max(maxx,sum);
	}cout<<maxx;
	return 0;
}

