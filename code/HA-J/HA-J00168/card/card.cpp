#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010];
void dfs(int x)
{
	if(x>n){
		return;
	}
	int c[500010];
	for(int i=x;i<=n;i++){
		c[i]=a[i];
	}
	for(int i=x;i<=n;i++){
		b[a[i]]++;
		for(int j=i-1;j>=x;j--){
			if(a[i]==a[j]){
				for(int k=i-1;k>=j;k--){
					b[c[k]]--;
					c[k]=0;
				}
				break;
			}
		}
	}
	dfs(x+1);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	queue<int>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
