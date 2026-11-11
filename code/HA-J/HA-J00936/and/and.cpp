#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0,minn=999999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxx){
			maxx=a[i];
		}
		if(a[i]<=minn){
			minn=a[i];
		}
	}
	cout<<maxx-minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
