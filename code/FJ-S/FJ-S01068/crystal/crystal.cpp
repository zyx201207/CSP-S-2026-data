#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m;
vector<int> v;
int ans=1;
int rtime=0;
int maxn=0;
int sum[N+5];
void dfs(int flo){
	
	int fll=0;
	for(int i=0;i<n;i++){
		rtime++;
		if(v[i]>maxn){
		
		fll=1;break;}
	}
	if(fll==1||ans==n)return;
//	for(int i=0;i<n;i++){
//		cout<<v[i]<<" ";
//	}
//	cout<<endl;
//	
	if(flo>m) return;int cnt=1;
	
	for(int i=1;i<n;i++){
		
		if(v[i]==v[i-1]){
			cnt++;
			ans=max(ans,cnt);
		}else cnt=1;
	}
	
	for(int i=0;i<n;i++){
		v[i]++;
		dfs(flo+1);
		v[i]--;
	}
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int ssum=0;
	for(int i=0;i<n;i++){
		ssum+=v[n-1]-v[i];
	}
	if(m>=ssum){
		cout<<n;
		cout<<0;
		return 0;
	}
	if(n<=20){
		maxn=v[n-1];
		dfs(0);
		cout<<ans;
	}else{
		int betw=v[1]-v[0];
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]+betw;
		}
		for(int i=n;i>=1;i--){
			if(m>=sum[i]){
				ans=i;
				break;
			}
		}
		cout<<ans;
	}

//	cout<<endl<<rtime;
	return 0;
}
