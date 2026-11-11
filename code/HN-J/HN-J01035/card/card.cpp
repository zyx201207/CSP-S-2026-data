#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
const int N=5e5+7891;
int n,m,a[N],r[N],ans[N],b[N];
bool fl=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)if(a[i]>a[i+1])fl=0;
	if(fl){
		for(int i=1;i<=n;i++)b[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<b[i]<<" ";
		return 0;
	}
	
	
	
	for(int i=n;i>=1;i--)if(!r[a[i]])r[a[i]]=i;
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			j=r[a[j]];
		}
	}
	for(int i=1;i<m;i++)cout<<ans[i]<<" ";
	cout<<ans[m];
	
	
	/*for(int i=1;i<=n;i=r[a[i]]+1){
		ans[a[i]]++;
		for(int j=i;j<=r[a[i]];j++){
			if(a[j]!=a[i])ans[a[j]]++;
		}
	}
	for(int i=1;i<m;i++)cout<<ans[i]<<" ";
	cout<<ans[m];*/
	return 0;
}
//luogu 991587
//J T4 dou bu hui? AFO ba
