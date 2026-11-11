#include<iostream>
using namespace std;
int n,m,a[200005][31],k[200005],ans,g;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=0;j<=30;j++) a[i][j]=((x>>j)&1);
	}
	for(int i=1;i<=n;i++) k[++g]=i;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=g;j++)
		if(a[k[j]][i]==1) cnt++;
		if(cnt<m) 
		continue;
		else{
			for(int j=1;j<=g;j++)
		    if(a[k[j]][i]==0) k[j]=0;
		    ans+=(1<<i);
		}
	}
	cout<<ans;
}
