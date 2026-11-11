#include<bits/stdc++.h>
using namespace std;
long long n,m,d[2009][2009],a[200099];
long long dp(long long i,long long dep){
	if(d[i][dep]!=-1) return d[i][dep];
	if(i>n&&dep<m) return d[i][dep]=0;
    if(dep==m) return d[i][dep]=a[i-1];
	long long res=0;
	res=max(dp(i+1,dep),a[i]&dp(i+1,dep+1));
	return d[i][dep]=res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(d,-1,sizeof(d));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dp(1,0);
	return 0;
} 
