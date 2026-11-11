#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],ans;
int r[32][200005],vis[50],dl[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n,greater<int>());
	
	vector<int> v;
	for(int i=1;i<=n;i++){
//		v.push_back(a[i]);
		int x=a[i],cnt=0;
		while(x){
			if(x&1) r[cnt][i]=1,vis[cnt]++;
			cnt++;
			x>>=1;
		}
	}
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	int t=35;
	
	while(t--){
		if(vis[t]>=m){
			for(int i=1;i<=n;i++){
				if(r[t][i]) v.push_back(a[i]);
			}
			break;
		}
	}
	while(t--){
		vector<int> tmp,v2;
		memset(dl,0,sizeof dl);
		if(v.size()==m) break;
		for(int i=0;i<v.size();i++){
			if(!(v[i]&(1<<t))){
				tmp.push_back(v[i]);
				dl[i]=1;
//				swap(v[i],v[v.size()-1]);
//				v.pop_back();
			}
		}
		for(int i=0;i<v.size();i++){
			if(!dl[i]) v2.push_back(v[i]);
		}
		if(v2.size()>=m){
			v.clear();
			for(int i=0;i<v2.size();i++) v.push_back(v2[i]);
		}
		
	}
	sort(v.begin(),v.end(),greater<int>());
	ans=v[0];
	for(int i=0;i<v.size();i++){
		if(i<m) ans&=v[i];
//		cout<<v[i]<<' ';
	}
	cout<<ans;
	
	return 0;
}

