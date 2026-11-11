#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],f[N];//f[i]=1能选 =0不能选 
int chk(int p){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!f[i])continue;
		if(a[i]&p)cnt++;	
		else f[i]=2;
	}
	if(cnt<m){
		for(int i=1;i<=n;i++){
			if(f[i]==2)f[i]=1;
		}
		return 0;	
	}
	for(int i=1;i<=n;i++){
		if(f[i]==2)f[i]=0;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1;
	}
	long long ans=0;
	for(int i=30;i>=1;i--){
		int k=1<<(i-1),ok=chk(k);
		if(ok)ans+=k;
	}
	cout<<ans;
	return 0;
}/*
5 3
31 3 1 15 7

*/
