#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],k=0,sum=0,vis[200005],va[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	k=log2(a[1]);
	while(k>=0){
		int cnt=0,p=(1<<k);
		k--;
		for(int i=1;i<=n;i++){
			if(a[i]<p)break;
			if(vis[i]!=1)continue;
			if((a[i]&p)==p)cnt++,va[i]=1;
		}
		if(cnt<m)continue;
		else{
			for(int i=1;i<=n;i++)vis[i]=va[i],va[i]=0;
			sum+=p;
		}
	}
	cout<<sum;
	return 0;
}
