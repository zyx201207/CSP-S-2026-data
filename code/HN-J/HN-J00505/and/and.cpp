#include<bits/stdc++.h>
using namespace std;
int x[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,x[i]);
		}
		cout<<maxx;
	}else{
		cout<<x[n];
	}
	return 0;
}

