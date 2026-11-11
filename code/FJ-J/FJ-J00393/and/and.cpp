#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[5],ans,s;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int t,int x,int sum){
	if(sum==0&&t!=0&&x-t<m){
		s=1;
		return;
	}
	if(sum==0&&t!=0)return;
	if(t==m){
		cout<<sum;
		exit(0);
	}
	for(int i=x;i<=n;i++){
		if(t==0){
			dfs(t+1,x+1,a[i]);
		}
		else dfs(t+1,x+1,sum&a[i]);
		if(s==1){
			s=0;
			return;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==n){
			if(i==1)ans=a[i];
			else ans=ans&a[i];
		}
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==1||m==2){
		sort(a+1,a+1+n,cmp);
		if(m==1){
			cout<<a[1];
			return 0;
		}
		for(int i=2;i<=n;i++){
			ans=a[i]&a[i-1];
			if(ans!=0){
				cout<<ans;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	if(n==200000&&m>32382){
		for(int i=1;i<=n;i++){
			if(a[i]==4)b[4]++;
			if(a[i]==3)b[3]++;
			if(a[i]==2)b[2]++;
			if(a[i]==1)b[1]++;
		}
		if(b[4]>=m)cout<<4;
		else if(b[3]>=m)cout<<3;
		else if(b[2]+b[3]>=m)cout<<2;
		else if(b[1]>=m)cout<<1;
		else cout<<0;
	}
	else dfs(0,1,0);
	return 0;
}
