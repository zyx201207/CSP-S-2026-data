#include<bits/stdc++.h>
using namespace std;
long long q,w,e,r,l,a[1010000],k,kl;
void dfs(long long z,long long x,long long p){
	if(x==w){
		l=max(l,z);
		return ;
	}
	for(int i=p+1;i<=q-w+x;i++){
		dfs(z&a[i],x+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>q>>w;
	for(int i=1;i<=q;i++){
		cin>>a[i];
		if((a[i]+1)%2!=0){
			k=1;	
		}
		kl=max(kl,a[i]);
	}	
	if(k==0&&q>2000){
		cout<<kl;
		return 0;
	}
	for(int i=1;i<=q-w+1;i++){
		dfs(a[i],1,i);
	}
	cout<<l;
	return 0;
}

