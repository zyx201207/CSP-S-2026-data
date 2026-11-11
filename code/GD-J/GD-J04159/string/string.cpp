#include<bits/stdc++.h>
using namespace std;
int n=0;
long long ans=0;
struct node{
	int sum=0;
	char ch;
}a[200010];
void dfs(int l,int r){
	while(l<r){
		if(a[l].ch!=a[r].ch){
		ans+=min(a[l].sum,a[r].sum);		
		}
		if(a[l].sum>a[r].sum){			
			a[l].sum=a[l].sum-a[r].sum;
			r--;
		}
		else if(a[l].sum<a[r].sum){			
			a[r].sum=a[r].sum-a[l].sum;
			l++;
		}
		else{			
			l++;
			r--;
		}
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;char cc;
		scanf("%d %c",&x,&cc);
		a[i].sum=x;
		a[i].ch=cc;		
	}
	dfs(1,n);
	printf("%lld\n",ans);
	return 0;
}
