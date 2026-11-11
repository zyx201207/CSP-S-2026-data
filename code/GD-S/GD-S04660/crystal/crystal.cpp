#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],now,ans,m1,max1=-1e9;
int solve(int j){
	for(int i=1;i<=n;i++)b[i]=0;
	b[j]=1;
	while(m>=0){
		while(a[now]==a[j]){
			b[now]=1;
			now++;
		}
		for(int i=j;i<=n;i++){
			if(b[i]){
				a[i]++;
				m--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i])ans++;
	}
	return ans;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		m=m1;
		ans=0;
		now=i+1;
		max1=max(max1,solve(i));
	}
	cout<<max1;
	return 0;
}
