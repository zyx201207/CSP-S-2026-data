#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
int n,m;
vector<int> ans;
int sum;
void dfs(int s,int cnt){
	/*if(cnt>m){
		for(auto q:ans){
			cout<<q<<' ';
		}
		cout<<endl;
		ans.clear();
		return ;
	}
	ans.push_back(s);
	for(int i=s+1;i<=n;i++){
		dfs(i,cnt+1);
	}*/
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	int alland;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]&(a[i]+1))!=0) f=0;
		if(i==1) alland=a[1];
		else alland&=a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int res=a[i]&a[j];
				maxn=max(maxn,res);
			}
		}
		cout<<maxn;
	} 
	else if(m==n){
		cout<<alland;
		return 0;
	} 
	else if(f){
		int sum=a[n-m+1];
		for(int i=n-m+2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	else if(n<=20){
		dfs(1,0);
		//for(auto q:ans) cout<<q<<endl;
	}
	return 0;
} 
