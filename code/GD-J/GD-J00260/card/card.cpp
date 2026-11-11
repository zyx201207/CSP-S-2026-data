#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int k;
int a[N],cnt[N],ans[200005];
int  main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(cnt[a[i]]==0) k++;
		cnt[a[i]]++;
	}

	if(k==m){
		for(int i=1;i<=m;i++){
			ans[i]=i;
		}
	}
	memset(cnt,0,sizeof(cnt));
	else {
	   
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
