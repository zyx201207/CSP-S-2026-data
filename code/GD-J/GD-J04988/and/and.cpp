#include <iostream>
using namespace std;

int n,m;
long long a[200005];
long long maX=-1;

void dfs(){
	
}

int main() {
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maX=max(maX,a[i]);
	}
	dfs();
	cout<<maX;
	
	
	return 0;
}

