#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,ans;
ll m;
ll E[500005];
ll B[500005];

void File(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}

int main(){
	File();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>E[i]; 
	}
	sort(E+1,E+n+1);
	for(int i=1;i<=n;i++){
		B[i]=B[i-1]+E[i];
	}
	int l=1,r=1;
	while(l<=n){
		while(r<=n&&E[r]*(ll)(r-l+1)-(B[r]-B[l-1])<=m){
			r++;
		}
		r--;
		ans=max(ans,r-l+1);
		l++;
	}
	cout<<ans;
	return 0;
}
/*
Orange AC
*/
