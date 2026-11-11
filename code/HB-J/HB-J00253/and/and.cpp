#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,maxn;
bool book[200005];
void dfs(int k,int num){
	if(k>m){
		maxn=max(maxn,num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[a[i]]==0){
			book[a[i]]=1;
			dfs(k+1,num&a[i]);
			book[a[i]]=0;
		}
	}
	return;	
}
/*int len(int a){
	int res=0;
	while(a){
		a>>=1;
		res++;
	}
	return res;
}
bool cmp(int x,int y){
	//if(len(x)!=len(y)) return len(x)>len(y);
	return x>y;
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*sort(a+1,a+1+n,cmp);
	maxn=a[1];
	for(int i=1;i<=n;i++){
		if(len(a[i])==len(a[i
	}*/
	for(int i=1;i<=n;i++){
		//book[a[i]]=1;
		dfs(1,a[i]);
		//book[a[i]]=0;
	}
	cout<<maxn;
	return 0;
}
