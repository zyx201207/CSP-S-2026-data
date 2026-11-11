#include<bits/stdc++.h>

using namespace std;
const int N=2e5+7;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int res=0;
	for(int i=29;i>=0;i--){
		int s=res|(1<<i);
		int req=0;
		for(int i=1;i<=n;i++) 
			if((a[i]&s)==s) req++;
		if(req>=m) res=s;
	}cout<<res;
	return 0;
}
