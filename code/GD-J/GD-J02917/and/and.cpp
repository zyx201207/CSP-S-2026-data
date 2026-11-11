#include<bits/stdc++.h>
using namespace std;
#define Freopen(x) _Freopen(#x)
void _Freopen(string file){
	freopen((file+".in").c_str(),"r",stdin);
	freopen((file+".out").c_str(),"w",stdout);
}
void Fclose(){
	fclose(stdin);
	fclose(stdout);
}
int n,m,a[1000005],ans;
void dfs(int i,int k,int s){
	if(i==n+1){
		if(k==m)ans=max(ans,s);
		return;
	}
	if(k<m)dfs(i+1,k+1,s&a[i]);
	dfs(i+1,k,s);
}
bool cmp(int x,int y){
	int x1=__builtin_popcount(x);
	int y1=__builtin_popcount(y);
	return x1>y1;
}
int main(int argc,char** argv){
	Freopen(and);
//	Freopen(card);
//	Freopen(string);
//	Freopen(travel);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,INT_MAX);
		cout<<ans;
	}else{
		sort(a+1,a+1+n,cmp);
		ans=INT_MAX;
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	Fclose();
	return EXIT_SUCCESS; 
}
