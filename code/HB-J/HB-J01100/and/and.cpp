#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n,m;
int a[N],b[N];
int maxx;
queue<int> q;
void put(){
	int ans=pow(2,31)-1;
	while(q.size()){
		int s=q.front();q.pop();
		ans&=s;
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		q.push(a[i]);
		maxx=max(maxx,a[i]);
	}
	for(int i=log2(maxx)+1; i>=1; i--){
		int sum=0;
		queue<int> p=q;
		int len=q.size();
		for(int j=1; j<=len; j++){
			int s=q.front();q.pop();
			int d=(s^(1<<(i-1))),t=1;
			if(d>s) t=0;
			//cout<<t<<" ";
			if(t==1) q.push(s);
			sum+=t;
		}
		//cout<<endl;
		if(sum==m){
			put();
			return 0;
		}
		else if(sum<m){
			q=p;
		}
	}
	int ans=pow(2,31)-1;
	for(int i=1; i<=m; i++){
		int s=q.front();q.pop();
		ans&=s;
	}
	cout<<ans;
	return 0;
}
