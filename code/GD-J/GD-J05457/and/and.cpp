#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=INT_MIN;
int a[1000000];
bool v[2000000];
void dfs(int sum,int k){
	if(k==0){
		maxx=max(maxx,sum);
		return ;
	}else{
		for(int i=1;i<=n;i++){
			if(v[i]==0){
				v[i]=1;
			    dfs(sum&a[i],k-1);
			    v[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
    	sort(a+1,a+1+n);
    	cout<<a[n];
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	v[i]=1;
    	dfs(a[i],m-1);
    	v[i]=0;
	}
    cout<<maxx;
	return 0;
}
