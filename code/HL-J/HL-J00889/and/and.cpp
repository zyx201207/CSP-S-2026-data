#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
vector<long long>a;
int v[222222];
bool cmp(long long a,long long b){return a>b;}
void dfs(int d,long long ax,int j){
	if(d==m){
		s=max(s,ax);
		return ;
	}
	for(long long i=j;i<n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(d+1,ax&a[i],j+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	if(m+1>=n){
		s=a[0];
		sort(a.begin(),a.end(),cmp);
		for(int i=1;i<m;i++){s&=a[i];}
	}
	else{dfs(0,pow(2,31)-1,0);}
	cout<<s;
	return 0;
}