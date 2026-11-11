#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxi=-1e18;; 
bool checkB(){
	for(int i=1;i<=n;i++){
		int x=a[i]+1;
		int y=log2(x);
		if((1<<y)!=x){
			return false;
		}
	}
	return true;
}
void dfs(int pos,int sum,int last,int gs){
	if(gs==m){
		maxi=max(maxi,sum);
		return ;
	}
	if(pos>n){
		return ;
	}
	for(int i=pos;i<=n;i++){
		if(gs==0){
			dfs(i+1,a[i],i,gs+1);
		}else{
			dfs(i+1,sum&a[i],i,gs+1);
		}
	}
	return;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];	
	}else if(m==2){ 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxi=max(maxi,(a[i]&a[j]));
			}
		}
		cout<<maxi;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(checkB()==true){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}else{
		dfs(1,0,0,0);
		cout<<maxi;
	}
	return 0;
}
