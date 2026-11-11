#include<bits/stdc++.h>

using namespace std;

int c,t1,ans;
int n,m;
vector<int> a[10010];
bool f[10010],t[10010];
int l[10010],len,d[10010];
void DFS(int x){
	t[x]=1;
	for(int i=0;i<a[x].size();i++){
		if(t[a[x][i]]==0) DFS(a[x][i]);
	}
}

void DFS2(int x,int sum){
	t[x]=1;
	d[x]=min(d[x],sum);
	for(int i=0;i<a[x].size();i++){
		if(t[a[x][i]]==0) DFS2(a[x][i],sum+1);
	}
}

void check(){
	len=0;
	int cnt=0,ma=INT_MIN;
	for(int i=1;i<=n;i++) d[i]=INT_MAX;
	for(int i=1;i<=n;i++) t[i]=0;
	for(int i=1;i<=n;i++) {
		if(f[i]==1) l[len++]=i;
	}
	if(len==0) return;
	for(int i=0;i<len;i++){
		if(t[l[i]]==0){
			DFS(l[i]);
			cnt++;
		}
	}
	if(cnt>2) return;
	for(int i=0;i<len;i++){
		for(int i=1;i<=n;i++) t[i]=0;
		DFS2(l[i],0);
	}
	for(int i=1;i<=n;i++){
		ma=max(ma,d[i]);
	}
	ans=min(ans,ma);
}

void func(int x,int cn){
	if(x==n){
		if(m==cn) check();
		return;
	}
	f[x]=1;
	func(x+1,cn+1);
	f[x]=0;
	if(cn<m) func(x+1,cn);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t1;
	for(int i=0;i<t1;i++){
		cin>>n>>m;
		for(int j=0;j<n-1;j++){
			int b,e;
			cin>>b>>e;
			a[b].push_back(e);
			a[e].push_back(b);
		}
		ans=INT_MAX;
		func(0,0);
		cout << ans << endl;
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
