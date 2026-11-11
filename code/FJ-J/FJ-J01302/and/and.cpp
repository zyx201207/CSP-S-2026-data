#include<bits/stdc++.h>
using namespace std;
int aaa[200010],a[200010];
int n,m,maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>aaa[i];
	sort(aaa+1,aaa+n+1);
	for(int j=1;j<=n-m+1;j++){
		int cnt=aaa[j];
		for(int i=j+1;i<=m+j-1;i++){
			cnt=cnt&aaa[i];
		}
		if(cnt>maxx)maxx=cnt;
	}
	cout<<maxx;
} 
