#include <bits/stdc++.h>
using namespace std;
int num[200001],n,m;
bool cmp(int a,int b){
	return a>b;
}
int find(int p,int c,int a){
	int ans=0;
	if(c==1){
		for(int i=p;i<=n;i++){
			ans=max(ans,a&num[i]);
		}
		return ans;
	}
	for(int i=p;i<=n-c+1;i++){
		ans=max(ans,find(i+1,c-1,a&num[i]));
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	if(m==1){
		sort(num+1,num+n+1,cmp);
		printf("%d",num[1]);
	}
	else if(m==n){
		int ans=num[1];
		for(int i=2;i<=n;i++) ans=ans&num[i];
		printf("%d",ans);
	}
	else{
		int ans=0;
		for(int i=1;i<=n-m+1;i++) ans=max(ans,find(i+1,m-1,num[i]));
		printf("%d",ans);
	}
	return 0;
}
