#include<bits/stdc++.h>
using namespace std;

long long maxnum=INT_MIN;
vector<long long> path;
vector<long long> a;
void dfs(long long startIndex,long long m,long long at,long long c){
	if(c-1<m-1) return;
	if(at==m){
		long long result=path[0];
		for(long long i=1;i<path.size();i++) result&=path[i];
		maxnum=max(result,maxnum);
		return;
	}
	for(int i=startIndex;i<a.size();i++){
		path.push_back(a[i]);
		dfs(i+1,m,at+1,c-1);
		path.pop_back();
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
    	int temp;
		cin>>temp;
		a.push_back(temp); 
	}
	for(int i=0;i<n;i++){
		dfs(i,m,0,n-i);
	}
	cout<<maxnum<<'\n';
	return 0;
}

