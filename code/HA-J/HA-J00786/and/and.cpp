#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010];
int maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxx){
			maxx=a[i];
		}
	}
	cout<<maxx;
	return 0;
}
