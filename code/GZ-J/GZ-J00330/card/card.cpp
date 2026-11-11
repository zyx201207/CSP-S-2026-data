//GZ-J00330 ³ÂÑåÑ®
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],t[M],sum[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)t[j]=0;
		for(int j=i;j<=n;j++){
			if(t[a[j]])for(int k=lower_bound(a+1,a+1+n,a[j])-a;k<j;k++)t[a[k]]-=1;
			t[j]+=1;
		}
		for(int j=1;j<=m;j++)if(t[j]==1)sum[j]++;
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
	return 0;
}
