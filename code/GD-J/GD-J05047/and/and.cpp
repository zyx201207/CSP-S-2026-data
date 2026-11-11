#include<bits/stdc++.h>
using namespace std;
long long a[200007];
int n,m;
long long ans=0;
long long sum(string s){
	long long cnt;
//	cout<<s[0]<<" ";
//	cout<<a[s[0]-'0']<<endl;
	cnt=a[s[0]-'0'];
//	cout<<cnt;
	for(int i=1;i<m;i++){
//		cout<<s[i]<<" ";
		
		cnt&=a[s[i]-'0'];
//		cout<<cnt<<" ";
	} 
//	cout<<endl;
//	cout<<cnt<<endl;
	return cnt;
}
void dfs(string s,int deep){
	if(deep==m){
//		cout<<sum(s)<<"\n";
		ans=max(ans,sum(s));
		return;
	}
	for(int i=s[deep];i<=n;i++){
		char c='0'+i;
		if(s.find(c)==-1){
			dfs(s+c,deep+1);
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(m==n){
		for(int i=1;i<=n;i++){
			long long b;
			cin>>b;
			if(i==1)ans=b;
			else ans&=b;
		}
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			long long b;
			cin>>b;
			ans=max(ans,b);
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else{
		int l=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=i-1)l=0;
		}
		if(l){
			cout<<n-m;
			return 0;
		}
		dfs("",0);
		cout<<ans;
	}
	return 0;
}
