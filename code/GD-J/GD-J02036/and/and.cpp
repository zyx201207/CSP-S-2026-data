#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+10;
int n,m;
int a[N],b[N],id[N],sum[N],c[N],d[N],ans[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	//5 3
	//31 3 1 15 7
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
		while(a[i]>=1){
			if(a[i]%2==1){
				sum[i]++;
			}
			a[i]/=2;
		}
		id[i]=sum[i];
	}
	sort(sum,sum+n,greater<>());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sum[i]==id[j]){
				c[i]=j;
			}
		}
	}
	if(m==1){
		cout<<b[c[0]];
		return 0;
	}
	ans[0]=b[c[0]]&b[c[1]];
	for(int i=1;i<=m-1;i++){
		ans[i]=ans[i-1]&b[c[i]];
	}
	cout<<ans[m-1];
	return 0;
}
