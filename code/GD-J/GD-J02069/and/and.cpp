#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define ll long long
int n,m,s[N],p[N];
ll ans,a[N];
void dfs(ll sum,int k,int last){
	if(k==m) {ans=max(ans,sum);return;}
	if(sum==0) return ;
	for(int i=last+1;i<=n;i++){
		dfs((sum&a[i]),k+1,i);
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n<=20&&m<=20){
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs((1<<30)-1,0,0);
		cout<<ans;
		return 0;
	}
	if(m==1) {
		for(int i=1;i<=n;i++) cin>>a[i],ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
		} 
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++) cin>>a[i],a[1]=(a[1]&a[i]);
		cout<<a[1];
		return 0;
	} 
	if(m==n-1){
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			if(i==1) ans=a[i];
			else ans=(ans&a[i]); 
		}
		ll k=(1<<30)-1;
		for(int i=1;i<=n;i++){
			if(ans==a[i]) continue;
			else k=(k&a[i]);
		} 
		cout<<k;
		return 0;
	}
	int p[5]={0};
	bool flag=0,flag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll w=a[i];
		while(w!=0){
			if(w%2==0) flag=1;
			w/=2;
			s[i]++;
		}
		if(a[i]>=4) flag2=false;
		else p[a[i]]++;
	}
	if(flag==0) {
		sort(s+1,s+n+1,cmp);
		cout<<(1<<s[m])-1;
		return 0;
	}
	if(flag2==true){
		if(m>p[3]) {
			m-=p[3];
			if(m>p[2]) {
				m-=p[2];
				if(m>p[1]) cout<<0;
				else cout<<1; 
			} else cout<<2;
		}else cout<<3;
		return 0;
	} 
	cout<<0;
	return 0;
}
