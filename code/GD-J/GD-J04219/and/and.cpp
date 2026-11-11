#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[200005];
bool f[200005];
int count(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]){
			continue;
		}
		cnt+=!!((1<<x)&a[i]);
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cn=n;
	for(int x=30;x>=0&&cn>m;x--){
		int c=count(x);
		if(c<m){
			continue;
		}
		for(int i=1;i<=n;i++){
			if(f[i]){
				continue;
			}
			if(!(a[i]&(1<<x))){
				f[i]=1;
				cn--;
				if(cn<=m){
					break;
				}
			}
		}
	}
	int ans=0xffffffff;
	for(int i=1;i<=n;i++){
		if(f[i]){
			continue;
		}
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
