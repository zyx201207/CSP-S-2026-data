#include<bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MAX,sna,a[200009];
bool p[200009];
int dfs(int x){
	int maxx=0;
	if(x==0)return INT_MAX;
	for(int i=0;i<n;i++){
		if(!p[i]){
			p[i]=1;
			maxx=max(maxx,dfs(x-1)&a[i]);
			p[i]=0;
		}
	}
	return maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	bool p=0;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int k=a[i]+1;
		if(k&-k!=k){
			p=1;
			break;
		}
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	else if(m==n){
		for(int i=0;i<n;i++)ans&=a[i];
		cout<<ans;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j)sna=max(sna,a[i]&a[j]);
			}
		}
		cout<<sna;
	}
	else if(!p){
		sort(a,a+n);
		for(int i=n-1;i>=n-m;i--)ans&=a[i];
		cout<<ans;
	}
	else{
		cout<<dfs(m);
	}
}

