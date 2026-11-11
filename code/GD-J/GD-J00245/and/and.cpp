#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ma[200010];
bool num[200010];
void dfs(int s){
	if(s>m){
		cout<<ma[s-1];
		return ;
	}
	int l=0; 
	for(int i=1;i<=n;i++){
		if(!num[i]){
			ma[s]=max(ma[s],ma[s-1]&a[i]);
			if(ma[s]==ma[s-1]&a[i]){
				l=i;
			}
		}
	}
	num[l]=1;
	dfs(s+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma[0]=max(a[i],ma[0]);
	}
	dfs(1);
	return 0;
} 
