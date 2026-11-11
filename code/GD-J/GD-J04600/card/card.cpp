#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005][3],ans[300005];
void ss(long long q){
	long long c[300005];
	memset(c,0,sizeof c);
	for(int i=q;i<=n;i++){
		if(c[a[i]]){
			for(int j=c[a[i]];j<=i;j++){
				c[a[j]]=0;
			}
			c[a[i]]=i;
		}else{
			c[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(c[i])ans[i]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ss(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
