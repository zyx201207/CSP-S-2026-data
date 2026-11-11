/*#include <bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
int a[mxn];
int vis[mxn];
int r[mxn];
//vector<int>dp[mxn];
int mx=-1;
int n,m;
void dfs(int x,int sum){
	if(x>m){
		//for(int i=1;i<=m;i++) cout<<r[i]<<" ";
		//cout<<endl;
		mx=max(mx,sum);
		return;
	}
	if(sum<mx) return;
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		r[x]=a[i];
		int d;
		if(x==1) d=a[i];
		else d=sum&a[i];
		dfs(x+1,d);
		vis[i]=0;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//dp[i].resize(m);
	}
	r[1]=a[1];
	dfs(1,1);
	cout<<mx;
	/*sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		long long x=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			x=(x&a[j]);
		}
		mx=max(mx,x);
	}
	int mx=-1;
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=min(m,i);k++){
				dp[i][k]=max(dp[i][k],dp[j][k-1]&a[i]);
				//cout<<dp[j][k-1]<<" "<<a[i]<<endl;
				if(i==n){
					mx=max(dp[i][k],mx);
				}
			}
		}
	}
//	cout<<mx;
}*/
#include <bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
int a[mxn];
priority_queue<pair<int,int> >q;
pair<int,int> rec[mxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and,out","w",stdout);
	int n,m;
	cin>>n>>m;
	int j=0;
	int pw=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmp=a[i],cnt=0;
		while(tmp){
			if(tmp%2==1) cnt++;
			tmp/=2;
		}
		q.push({cnt,a[i]});
	}
	/*sort(a+1,a+n+1);
	int num=-1,st,ed;
	for(int i=1;i<=n;i++){
		if(a[i]>(1<<j)){
			rec[j+1].first=i;
			rec[j].second=i-1;
			if(rec[j].second-rec[j].first+1>num){
				num=rec[j].second-rec[j].first+1;
				st=rec[j].first,ed=rec[j].second;
			}
			j++;
		}
	}

	int mx2=-1;
	cout<<"d:"<<ed-st+1<<endl;
	//f(ed-st+1>=m){
	for(int i=st;i<=ed;i++){
		if(i==st){
			mx2=a[i];
			continue;
		}else mx2=(mx2&a[i]);
	}
	//}*/
	//cout<<"input complete"<<endl;
	int ans=-1;
	for(int i=1;i<=m;i++){
		if(i==1){
			ans=q.top().second;
			q.pop();
			continue;
		}
		ans=(ans&q.top().second);
		q.pop();
	}
	/*int i=m;
	int ans=-1;
	while(i--){
		if(i==m){
			ans=a[q.top().second];
			q.pop();
			cout<<ans<<endl;
			continue;
		}
		ans=(ans&a[q.top().second]);
		q.pop();
	}*/
	cout<<ans;
	return 0;
}

