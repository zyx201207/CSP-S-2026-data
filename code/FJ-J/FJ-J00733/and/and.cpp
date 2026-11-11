#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[300000];
int ans,sum;
bool v[300000];
vector<int>s;
void dfs(int x){
	if(x==m){
		sum=s[1];
		for(int i=1;i<=x;i++){
			sum=a[s[i]]&sum;
//			cout<<s[i];
		}
//		cout<<endl;
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			s.push_back(i);
			dfs(x+1);
			v[i]=0;
			s.pop_back();
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
//hello~~~~~

