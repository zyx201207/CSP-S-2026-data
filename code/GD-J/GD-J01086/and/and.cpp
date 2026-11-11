#include<bits/stdc++.h>
using namespace std;
int n,a[2*114514],m,ans=-114514; 
void solve(vector<int>v,int k,int m){
	if(m==0){
		int anss=v[0];
		int sze=v.size();
		for(int i=1;i<sze;i++){
			anss&=v[i];
		}

		if(anss>ans)ans=anss;
		return;
	}
	int t=n-m+1;
	for(int i=k;i<t;i++){
		v.push_back(a[i]);
		solve(v,i+1,m-1);
		v.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int>v;
	solve(v,0,m);
	cout<<ans;
	return 0;
}

