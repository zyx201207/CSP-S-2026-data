#include <bits/stdc++.h>
using namespace std;
int n,m,maxx=-1202;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			cnt|=a[i+j];
		}
		if(cnt>maxx){
			maxx=cnt;
		}
	}
	cout<<maxx;
	return 0;
}

