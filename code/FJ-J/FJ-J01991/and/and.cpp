#include<bits/stdc++.h>
using namespace std;
const int M=2*1e5+5;
int n,m,a[M],b[M];long long ans=INT_MIN;
int zh(int x,int m){
	stack<int>s;
	int sum=0;
	while(x>0){
		int y=x%m;
		s.push(y);
		x/=m;
	}
	while(!s.empty()){
		int z=s.top();
		sum=sum*10+z;
		s.pop();
	}
	return sum;
}
int suan(){
	int sum=a[b[1]];
	for(int i=2;i<=m;i++){
		sum=sum&&a[b[i]];
	}
	return sum;
}
void dfs(int x){
	if(x==m+1){
		long long s=suan();
		ans=max(ans,s);
		return;
	}
	for(int i=b[x-1]+1;i<=n-m+1;i++){
		b[x]=i;
		dfs(x++);
		b[x]-=i;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=zh(a[i],2);
	}
	dfs(1);
	int sum=0;
	while(ans!=0){
		int r=ans%10,f=0;
		sum+=pow(r,++f);
		ans/=10;
	}
	cout<<ans; 
	return 0;
}
