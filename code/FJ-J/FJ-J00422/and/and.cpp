#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ans,si=1,s,d;
int y=1;
long long a[20005];
bool vis[20005];
void dfs(int x){
	if(si>=m){
		ans=max(ans,sum);
		return;
	}for(int j=x;j<n;j++){
	for(int i=j+1;i<=n;i++){
			s=a[j];
		s=s&a[i];
		sum=s;
		si++;
		dfs(i);
		si--;
	}}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int a1=a[i]+1;
		if(a1!=i){
			y=0;
		}
		while(a1%2==0){
			a1/=2;
			if(a1==1){
				d++;
			}
		}
	}
	if(d==n||y==1){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]<a[j]){
					swap(a[i],a[j]);
				}
			}
		}ans=a[m];
	}
	else{
		dfs(1);
	}
	cout<<ans;
	
    return 0;
	
}
