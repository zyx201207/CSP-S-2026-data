#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
pair<int,int> ans[2000010];
int o;
long long n,d;
void dfs(int x,int l){
	if(ans[x].first>l){
		ans[x].first=l;
		if(ans[x].second==2)o--;
		ans[x].second=1;
	}
	else if(ans[x].first==l){
		ans[x].second++;
		if(ans[x].second==2){
			o++;
		}
		if(ans[x].second==3)o--;
	}
	for(int i=x+1;i<=n&&a[i]-a[x]<=d;i++){
		dfs(i,l+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >>c>>t;
	while(t--){
		cin >>n>>d;
		bool Y=1;
		for(int i=1;i<=n;i++){
			cin >>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])Y=0;
		}
		if(Y&&n>=10000){
			long long pd=a[2]-a[1];
			int r=(n+1)/2;
			if((n+1)/2%pd!=0)r++;
			if(d<=2*pd-1||d>=pd*r){
				cout<<0<<'\n';
				continue;
			}
			long long p=(d-2*pd+1)/pd;
			if((d-2*pd+1)%pd!=0)p++;
			cout<<n-p*2-1<<'\n';
		}
		else{
			int ss=0;
			for(int i=1;i<=n;i++){
				memset(ans,0x3f,sizeof ans);
				o=0;
				dfs(i,0);
				ss+=o;
			}
			cout<<ss<<'\n';
		}
	}
	return 0;
} 
