#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1,j=1,cost=0;i<=n;++i){
		cost+=(i-j)*(a[i]-a[i-1]);
		while(cost>m&&i>=j){
			cost-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1); 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

