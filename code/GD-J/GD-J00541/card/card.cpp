#include<bits/stdc++.h>
using namespace std;
int n,m,a[501000],b[501000],c[501000],ANS[501000];
vector<int>ans[501000];
bool check(){
	for(int i=1;i<n;i++)if(a[i]>a[i+1])return 0;
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[a[i]]++;
	if(check()){
		for(int i=1;i<=n;i++)
			ANS[a[i]]=max(ANS[a[i]],i);
		for(int i=1;i<=m;i++)printf("%d ",ANS[i]);
		return 0;
	}
	for(int i=n;i>=1;i--)if(b[a[i]]==0)b[a[i]]=i;
	ans[n]={a[n]};
	for(int i=n-1;i>=1;i--){
		if(b[a[i]]!=i)ans[i]=ans[b[a[i]]];
		else ans[i]=ans[i+1],ans[i].push_back(a[i]);
	}
	for(int i=1;i<=m;i++) for(auto x:ans[b[i]]) ANS[x]+=c[i];
	for(int i=1;i<=m;i++) printf("%d ",ANS[i]);
}
