#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans1,ans2,ans3=(1<<30)-1,ans4;
void dfs(int k,int v,int li){
	if(n-li<m-k)return;
	if(k==m){
		ans1=max(ans1,v);
		return;
	}
	for(int i=li;i<n;i++){
		dfs(k+1,v&a[i],i+1);
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans2=max(ans2,a[i]);
		ans3&=a[i];
	}
	if(m==1)cout<<ans2;
	else if(m==n)cout<<ans3;
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				ans4=max(ans4,a[i]&a[j]);
			}
		}
		cout<<ans4;
	}
	else if(m==n-1){
		int fr[200005]={a[0]},ba[200005]={a[n-1]};
		for(int i=1;i<n;i++){
			fr[i]=a[i]&fr[i-1];
		}
		for(int i=n-2;i>=0;i--){
			ba[i]=a[i]&ba[i+1];
		}
		int ans=max(ba[1],fr[n-2]);
		for(int i=1;i<n-1;i++){
			ans=max(ans,fr[i-1]&ba[i+1]);
		}
		cout<<ans;
	}
	else if(ans2<4){
		int t[5]={};
		for(int i=0;i<n;i++){
			t[a[i]]++;
		}
		if(t[3]>=m)cout<<3;
		else{
			if(t[2]+t[3]>=m)cout<<2;
			else{
				if(t[1]+t[3]>=m)cout<<1;
				else cout<<0;
			}
		}
	}
	else if(n<=20){
		dfs(0,(1<<20)-1,0);
		cout<<ans1;
	}
	else{
		sort(a,a+n,greater<int>());
		cout<<a[m-1];
	}
}
