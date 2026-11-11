#include<bits/stdc++.h>
using namespace std;

long long maxn=-1;
long long m,n;
vector<long long> a;
vector<long long> ans;
vector<vector<long long> > s;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	a.resize(n+1,0);
	ans.resize(n+1,0);
	s.resize(n+1,vector<long long>(n+1,0) );
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	sort(a.begin() + 1,a.begin() + n + 1,[](const long long& a,const long long& b){
		return  a < b;
	});
	
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(i != j){
				long long sum = a[j] - a[i];
				if(sum < 0)sum *= -1;
				s[j][i] = s[i][j] = sum;
			}
		}
	}
	
	for(int j = 1;j <= n;j++){
		int i = 1;
		long long rem = m;
		while(s[i][j] <= rem){
			ans[j]++;
			i++;
			rem-=s[i][j];
		}
	}
	
	for(int i = 1;i <= n;i++){
		maxn = max(ans[i],maxn);
	}
	cout<<maxn;
	return 0;
}

