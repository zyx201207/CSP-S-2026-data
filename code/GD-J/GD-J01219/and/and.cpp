#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],t,vis[200005],cnt,vis2[200005],ans;
vector<ll>c[35];
void f(ll x,ll id){
	t=0;
	while(x){
		if(x%2==1){
			c[t].push_back(id);
		}
		x/=2;
		t++;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		f(a[i],i);
	}
	t=-1;
	for(int i = 30;i >= 0;i--){
		if(c[i].size()>=m){
			t=i;
			break;
		}
	}
	if(t==-1){
		cout<<0;
	}else{
		for(int i = 0;i < c[t].size();i++){
			vis[c[t][i]]=1;
		}
		ans=(1<<t);
		for(int i = t-1;i >= 0;i--){
			cnt=0;
			for(int j = 1;j <= n;j++)vis2[j]=0;
			for(int j = 0;j < c[i].size();j++){
				vis2[c[i][j]]=1;
				if(vis[c[i][j]]==1)cnt++;
			}
			if(cnt>=m){
				for(int i = 1;i <= n;i++){
					vis[i]=(vis[i]&vis2[i]);
				}
				ans+=(1<<i);
			}
		}
	}
	cout<<ans;
	return 0;
}
