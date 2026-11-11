#include<bits/stdc++.h>
using namespace std;
long long a,s,arr[200010],xz[200010],ans=0;
void dfs(long long q,long long num,long long w){
	if (q==s){
		ans=max(ans,num);
		return;
	}
	if (q==0){
		for (int i=w; i<a; i++){
			if (xz[i]==0){
				xz[i]=1;
				dfs(q+1,arr[i],i+1);
				xz[i]=0;
			}
		}
	}else{
		for (int i=w; i<a; i++){
			if (xz[i]==0){
				xz[i]=1;
				dfs(q+1,num&arr[i],i+1);
				xz[i]=0;
			}
		}
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>a>>s;
	for (int i=0; i<a; i++){
		cin >>arr[i];
	}
	dfs(0,0,0);
	cout <<ans;
	return 0;
} 
