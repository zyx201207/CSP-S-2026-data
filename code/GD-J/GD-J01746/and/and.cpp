#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,a[200005];
bool il2(int x){
	int q=log2(x);
	return (1<<q)==x;
}
void solve(){
	cin>>n>>m;
	if(m==1) { cout<<"0\n"; return; }
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int tmp=a[i]&a[j];
				if(maxx<tmp) maxx=tmp;
			}
		}
		cout<<maxx<<'\n';
		return;
	}
	if(m==n){
		a[0]=INT_MAX;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]&=a[i-1];
		}
		cout<<a[n]<<'\n';
		return;
	}
	if(m==n-1){
		int minn=INT_MAX,mini=0,ans=INT_MAX;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<minn) minn=a[i],mini=i;
		}
		for(int i=1;i<=n;i++){
			if(mini!=i) ans&=a[i];
		}
		cout<<ans<<'\n';
		return;
	}
	bool fa=1,f4=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(fa&&!il2(a[i]+1)) fa=0;
		if(f4&&a[i]>=4) f4=0;
		if(a[i]<4) p[a[i]]++;
	}
	if(f4){
		if(p[3]>=m) cout<<"3\n";
		else if(p[3]+p[2]>=m) cout<<"2\n";
		else if(p[3]+p[1]>=m) cout<<"1\n"; 
		else cout<<"0\n";
		return;
	}
	if(fa){
		sort(a+1,a+n+1,greater<int>());
		a[0]=INT_MAX;
		for(int i=1;i<=m;i++){
			a[i]&=a[i-1];
		}
		cout<<a[m]<<'\n';
		return;
	}
	if(p[0]>n-m) { cout<<"0\n"; return; }
	cout<<"0\n";
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
