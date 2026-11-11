#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i,j,ans=0;
	cin>>n>>m>>i>>j;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		cin>>ans;
		if(a[i]+1==a[j]){
		ans=(a[i]+a[j]); ans++;
		cout<<ans<<endl;
	}
	else cout<<"3\n";
	}	

	return 0;
} 
