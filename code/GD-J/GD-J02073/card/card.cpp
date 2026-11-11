#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int max1[500001],min1[500001];
int max2;
deque<int> s;
int b[500001];
int ans[500001];
int tree[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(b,0,sizeof(b));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		max1[a[i]]=i;
	}
	memset(tree,5000001,sizeof(tree));
	for(int i=1;i<=n;i++)
		tree[i]=max1[a[i]];	
	for(int i=n;i>=1;i--){
		int j=i;
		while(j<=n){
			ans[a[j]]++;j=tree[j]+1;
		}		
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<" ";	
	return 0;
}
