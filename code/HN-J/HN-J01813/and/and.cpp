#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],b[N],mx;
map<long long,long>mp;
void dfs(int l,int si){
	if(l>m){
		for(int i=1;i<=m-1;i++){
			b[i]&=b[i+1];
		}
		mx=max(b[m-1],mx);
		return;
	}
	for(int i=si;i<=n;i++){
		b[l]=a[i];
		dfs(l+1,i+1);
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==1){
			mx=max(a[i],mx);
		}
	}
	if(m!=1){
		dfs(1,1);
	}
	
	cout<<mx;
	return 0;
}
