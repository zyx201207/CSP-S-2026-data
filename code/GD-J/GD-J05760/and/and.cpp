#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],s,d;
void dfs(int x,int y,int z,int e,long long w){
	if(d==1000000000)
		cout<<max(s,w);
	if(z==y){
		s=max(s,w);
		return;
	}for(int i=e+1;i<=x;i++)
		dfs(x,y,z+1,i,w&a[i]),d++;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-m+1;i++)
		dfs(n,m,1,i,a[i]);
	cout<<s;
	return 0;
} 
