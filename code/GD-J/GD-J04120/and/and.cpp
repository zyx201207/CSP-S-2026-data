#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long c[N],a[N],n,m,ans=0;
bool v[N];
void dfs(long long id){
	if(id==m){
		long long b=c[0];
		for(int i=1;i<m;i++){
			b&=c[i];
		}
		if(ans<=b){
			ans=b;
		}
		return ;
	}
	else{
		for(int i=id;i<n;i++){
			if(v[i]==0){
				v[i]=1;
				c[id]=a[i];
				dfs(id+1);
				v[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
