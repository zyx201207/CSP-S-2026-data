#include<bits/stdc++.h>
using namespace std;
long long c,n,m,t,a[10101010],cnt,mb,way,fl=1;
void dfs(int x,int xst){
	if(x==mb){
		if(cnt==xst)way++;
		return ;
	}
	
	long long lj=0,ll=1;
	while(lj<=m){
		lj=a[x+ll]-a[x];
		if(lj<=m&&x+ll<=mb)dfs(x+ll,xst+1);
		ll++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long cct=0;
		cin>>n>>m;
		if(m>=n||m==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int uuu=a[2]-a[1];
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]!=uuu){
				fl=0;
				break;
			}
		}
		if(fl&&n>=5000){
			m/=uuu;
			m++;
			cout<<n-m+1<<endl;
			continue;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				long long f=1;
				for(int k=i;k<=j;){
					cnt++;
					long long lj=0,ll=0;
					while(lj<=m){
						lj+=a[k+ll]-a[i];
						ll++;
					}
					k+=ll;
					if(lj==0){
						f=0;
						break;
					}
				}
				if(!f)continue;
				way=0;
				mb=j;
				dfs(i,0);
				if(way==2)cct++;
			}
		}
		cout<<cct<<endl;
	}//0 2 4 2 1 2 3 4
	return 0;
} 
