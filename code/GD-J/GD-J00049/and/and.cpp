#include<bits/stdc++.h>
using namespace std;
long long n,r,a[200100];
int ma=-1e2;
bool k[200100];
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(int st,int s){
	if(st==r){
		ma=max(ma,s);
		return;
	}
	for(int i=0;i<n;i++){
		if(k[i]==0){
			k[i]=1;
			dfs(st+1,s&a[i]);
			k[i]=0;
			
		}
	}
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>r;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		k[i]=1;
		dfs(1,a[i]);
		k[i]=0;
	}
	cout<<ma;
	return 0;
} 
