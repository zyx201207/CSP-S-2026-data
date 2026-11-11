#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>a;
struct se{
	long long ma=0,ge=1;
}op[10000][10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,k;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k;a.push_back(k);
	}sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(op[i-1][j].ma+a[i]-a[i-1]<=m){
				op[i][j+1].ma=op[i-1][j].ma+a[i]-a[i-1];
				op[i][j+1].ge=op[i-1][j].ge+1;
			}
		}
	}long long maxn=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			maxn=max(op[i][j].ge,maxn);
		}
	}
	cout<<maxn;
	return 0;
} 
