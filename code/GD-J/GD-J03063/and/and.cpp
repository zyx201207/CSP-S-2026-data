#include<bits/stdc++.h>
using namespace std;
long long a[200010],d[2005],anss;
int n,m;
bool mk[2005];
void dfs(int x){
	if(x>m){
		long long cnt=d[1];
		for(int i=1;m>=i;i++){
			cnt&=d[i];
		}
		anss=max(anss,cnt);
		return;
	}
	for(int i=1;n>=i;i++){
		if(!mk[i] && d[x-1]<=a[i]){
			mk[i]=1;
			d[x]=a[i];
			dfs(x+1);
			mk[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mi=999999999999;
	for(int i=1;n>=i;i++){
		cin>>a[i]; 
		mi=min(mi,a[i]);
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;n>=i;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else{
		if(n==m-1 && n>2000){
			long long ans=a[1];
			for(int i=1;n>=i;i++){
				if(mi!=a[i])ans&=a[i];
			}
			cout<<ans;
		}
		else{
			if(n<=2000){
				dfs(1);
				cout<<anss;
			} 
			else{
				long long ans=a[1];
				for(int i=1;m>=i;i++){
					ans&=a[i];
				}
				cout<<ans;
			}
		}
		
	}
	return 0;
} 


