#include<bits/stdc++.h>
using namespace std;
long long m,n,ans=0,f,arr[200010],b[200010],yhh;
void dfs(long long wz,long long sl){
	if(wz==m){
		if(sl==n){
			yhh=int(b[0]&b[1]);
			for(int i=2;i<n;i++){
				yhh=int(yhh&b[i]);
			}
		ans=max(ans,yhh);	
		}
		return;
	}
	if(sl==n)dfs(wz+1,sl);
	dfs(wz+1,sl);
	b[f]=arr[wz];
	f++;
	dfs(wz+1,sl+1);
}
int main(){
	long long zdz=0;
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>arr[i];
		zdz=max(zdz,arr[i]);
	}
	if(n==1){
		cout<<zdz;
		return 0;
	}
	int yhg=0;
	if(n==m){
		for(int i=0;i<m-1;i++){
		yhg=arr[i]&arr[i+1];
	}
	cout<<yhg;
	return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
//0000 0011 0000 1111
//if(1==1)cout<<1,if(1!=0)cout<<0;
