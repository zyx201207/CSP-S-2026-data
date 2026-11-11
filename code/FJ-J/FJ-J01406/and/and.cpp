#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=-1e9,s,ss,u;
long long bfs(vector<long long>&a , long long mxx){
	s=-1;
	long long mx=-1e9;
	for(long long i=0;i<a.size();i++){
		if(a[i]!=-1){
			mx=max(mx,mxx&a[i]);
			s=i;
		}
	}
	if(s!=-1){
//		cout<<s<<" "<<a[s]<<'\n';
		a[s]=-1;
	}
	return mx;
}
int dfs(vector<long long>&a,long long mxx,long long &m){
	while(m--){
		int t=mxx;
		mxx=bfs(a,t);
//		cout<<mxx<<'\n';
	}
	return mxx;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<long long>a;
	for(int i=0;i<n;i++){
		cin>>u;
		a.push_back(u);
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			if(mx<(a[i]&a[j])){
				s=i,ss=j;
			}
			mx=max(mx,a[i]&a[j]);
		}
	}
//	cout<<s<<" "<<a[s]<<'\n';
//	cout<<ss<<" "<<a[ss]<<'\n';
	m-=2;a[s]=-1,a[ss]=-1;
//	cout<<mx<<'\n';
	cout<<dfs(a,mx,m);
	return 0;
} 
/*
15      7 
1111   111
*/
