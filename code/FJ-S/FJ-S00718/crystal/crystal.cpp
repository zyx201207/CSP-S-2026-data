#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN],b[0x3f3f3f],n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m>0){
		m-=(ans+1);
		ans++;
	}
	cout<<ans;
	
	return 0;
}
