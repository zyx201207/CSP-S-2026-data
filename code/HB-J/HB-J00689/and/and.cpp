#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],minn=1,maxn=0;
int book[200005];
int flag=0;
void dfs(int step,long long now)
{
	if(step>m){
		maxn=max(maxn,now);
		flag=0;
		return ;
	}
	for(int i=minn;i<=n;i++)
	{
		if(a[i]<maxn){
			continue;
		}
		else if(a[i]>=maxn && flag==0){
			flag=1;
			if(minn>i){
				minn=i;
			}
		}
		if(book[i]==1){
			continue;
		}
		book[i]=1;
		if(step==1){
			now=a[i];
		}
		dfs(step+1,now&a[i]);
		book[i]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<maxn;
	return 0;
}
