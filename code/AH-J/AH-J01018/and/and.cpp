#include<bits/stdc++.h>
using namespace std;
int n,m;
long  a[200010];
long long ans=LONG_LONG_MIN;
void dfs(int i,long long num,int ch){
	//cout<<num<<endl;
	if(ch==m){
		ans=max(ans,num);
		return;
	}
	if(i>n){
		return;
	}
	dfs(i+1,num,ch
	);
	long long tmp=num&a[i];
	ch++;
	dfs(i+1,tmp,ch);
	ch--;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,pow(2,30)-1,0);
	cout<<ans;
	return 0;
}
