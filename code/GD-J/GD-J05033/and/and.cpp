#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans=0;
int a[N];
int e[N],cot[50];
vector<int> c[N];
bool f=1;
void build(int x){
	int cnt=0;
	for(int i=0;i<=n;i++)e[i]=0;
	while(x){
		e[++cnt]=x%2;
		x/=2;
	}
}
int pw(int n,int x){
	int res=1;
	while(x--){
		res*=2;
	}
	return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++)c[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i],cnt=0;
		while(t){
//			cnt++;
			c[i][cnt]=(t%2);
			cnt++;
			t/=2;
		}
		for(int j=0;j<=15;j++){
//			if(j>)
			swap(c[i][j],c[i][29-j]);
//			cout<<j<<" "<<c[i].size()-1-j<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++){
//			cout<<c[i][j];
			if(c[i][j]==1)cot[j]++;
		}
//		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=pw(2,c[i].size())-1)f=0;
	}
	if(n<=20){
		for(int i=pw(2,m)-1;i<=pw(2,n)-1;i++){
			build(i);
			int cnt=0,v=pw(2,30)-1;
			for(int j=1;j<=n;j++){
				if(e[j]){
					cnt++;
					v&=a[j];
				}
			}
			if(cnt!=m)continue;
			ans=max(ans,v);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
//		cout<<1<<endl;
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1]<<endl;
		return 0;
	}
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n){
		int v=pw(2,30)-1;
		for(int i=1;i<=n;i++){
			v&=a[i];
		}
		cout<<v<<endl;
		return 0;
	}
	bool ff=0;
	queue<int> q;
	for(int i=0;i<30;i++){
		if(cot[i]==0)continue;
		if(cot[i]<m)continue;
		if(ff==0){
			for(int j=1;j<=n;j++){
				if(c[j][i]==1)q.push(j);
			}
			ff=1;
//			cout<<cot[i]<<endl;
			ans+=pw(2,29-i);
		}
		else {
			int cnt=0;
			queue<int> nq;
			int nn=q.size();
			for(int j=1;j<=nn;j++){
				int t=q.front();
				q.pop();
				if(c[t][i]==1){
					cnt++;
					q.push(t);
				}
				nq.push(t);
			}
//			cout<<cnt<<endl;
			if(cnt>=m){
				ans+=pw(2,29-i);
				continue;
			}
			else{
				while(!q.empty())q.pop();
				while(!nq.empty()){
					q.push(nq.front());
					nq.pop();
				}
			}
		}
//		ans+=pw(2,30-i);
	}
	cout<<ans;
	return 0;
}
