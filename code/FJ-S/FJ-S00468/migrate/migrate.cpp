#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,su;
long long x[2000006],s[2000006];
void dfs(int u,int v,int cnt,int t){
	if(u==v&&cnt==t)su++;
	else{
		int k=u+1;
		while(x[u]+d>=x[k]&&k<=v){
			dfs(k,v,cnt+1,t);
			k++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long sum=0;
		cin>>n>>d;
		int k=1;
		for(int i=1;i<=n;i++){
			s[i]=n;
			cin>>x[i];
			while(x[k]+d<x[i]){
				s[k]=i-1;
				k++;
			}
		}
//		for(int i=1;i<=n;i++)cout<<s[i]<<" ";
//		cout<<"\n";
		int cnt;
		for(long long u=1;u<=n-3;u++){
			for(long long v=u+3;v<=n;v++){
				su=0;cnt=1;k=u;
				while(s[k]<v&&k!=s[k])cnt++,k=s[k];
				dfs(u,v,0,cnt);
				if(su==2)sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
