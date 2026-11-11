#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool b[200005];
int dfs(int x,int len){
	if(len==1){
		return a[x];
	}
	b[x]=1;
	int mx=-1;
	for(int i=0;i<n;i++){
		if(i!=x&&b[i]==0){
			mx=max(mx,a[x]&dfs(i,len-1));
		}
	}
	b[x]=0;
	return mx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		int mx=-1;
		for(int i=0;i<n;i++){
			mx=max(mx,dfs(i,m));
		}
		cout<<mx;
    	}
    else{
		sort(a,a+n);
		cout<<a[n-m];
	}
	return 0;
}

