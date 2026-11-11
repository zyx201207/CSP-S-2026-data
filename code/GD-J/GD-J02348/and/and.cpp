#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
long long ans;
long long dfs(int now,int cnt,int num){
//	cout<<now<<" "<<cnt<<" "<<num<<endl;
	if(cnt==m){
		return num;
	}
	if(now>n){
		return 0;
	}
	now+=1;
	long long i=dfs(now,cnt,num);
	if(cnt==0){
		num=a[now-1];
	}
	return max(i,dfs(now,cnt+1,num&a[now-1]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,0);
	return 0;
}
