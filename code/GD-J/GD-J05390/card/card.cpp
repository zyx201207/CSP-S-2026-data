#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,io1=1,io2=1,a[500005],ans[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
//	vector<int> a(n+20),ans(m+20);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) io1=0;
	}
	if(io1){
//		cout<<111;
//		for(int k=1;k<=n;k++){
//			memset(vis,0,sizeof vis);
//			for(int i=k;i<=n;i++){
//				vis[a[i]]=1;
//			}
//			for(int i=1;i<=m;i++) if(vis[i]) ans[i]++;
//		}
		for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],i);
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	if(m==2){
		ans[a[n]]=n;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]) ans[a[i]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	for(int k=1;k<=n;k++){
		memset(vis,0,sizeof vis);
		vector<int> v;
		v.push_back(-1);
		for(int i=k;i<=n;i++){
	//		cout<<i;
			if(vis[a[i]]){
	//			cout<<i;
				int t=v.size()-1;
	//			cout<<i;
	//			cout<<t<<' '<<vis[a[i]]<<endl;
				for(int j=t;j>=vis[a[i]];j--){
					vis[v[j]]=0;
					if(v.size()) v.pop_back();
				}
			}
			v.push_back(a[i]);
			vis[a[i]]=v.size();
			
		}
		for(int j=1;j<=m;j++){
			if(vis[j]) ans[j]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
	

}
/*
5min
about 300pts
next monday qizhong test
S will waste my time cause idk how to do
good luck
*/
