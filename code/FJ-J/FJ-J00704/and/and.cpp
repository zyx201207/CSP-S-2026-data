#include<bits/stdc++.h>
using namespace std;
long long*arr;
int n,m,ma=0;
void dfs(long long w,int d,int last,int s){
	if(n-d-1<s){
		return;
	} 
	if(d>=n){
		if(s==0&&w>=ma)ma=w;
		return;
	}
	if(s==0){
		if(w>ma)ma=w;
		return;
	}
	for(int i=last+1;i<n;++i){
		dfs((w==-1?arr[i]:w&arr[i]),d+1,i,s-1);
		dfs(w,d+1,i,s);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	arr=new long long[n];
	for(int i=0;i<n;++i)cin>>arr[i];
	if(n>30){
		for(int i=0;i<n;++i)if(arr[i]>ma)ma=arr[i]; 
	}else dfs(-1,0,-1,m);
	cout<<ma;
	return 0;
}
