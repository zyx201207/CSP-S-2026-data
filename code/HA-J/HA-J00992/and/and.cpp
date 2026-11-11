#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[200005];
void dfs(int number,int now_int,int startindex){
	if(number==m){
		ans=max(ans,now_int);
		return;
	}
	for(int i=startindex;i<=n;i++){
		number++;
		dfs(number,now_int&a[i],i+1);
		number--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,pow(2,31)-1,1);
	cout<<ans;
	return 0;
}

