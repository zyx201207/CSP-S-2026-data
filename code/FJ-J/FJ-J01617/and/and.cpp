#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long s[200005];
long long v[200005];
long long cnt=0;
void dfs(long long step,long long sum,long long l){
	if(step==m){
		cnt=max(cnt,sum);
		return ;
	}
	for(int i=l;i<=n;i++){
		if(step==0){
			s[i]=1;
			
			dfs(step+1,a[i],i+1);
			s[i]=0;
		}
		else if(s[i]==0){
			s[i]=1;
			
			dfs(step+1,sum&a[i],i+1);
			s[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<cnt;
	
	return 0;
}
