#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005],ans,cnt=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) ans=a[i];
		ans=ans&a[i];
		cnt=max(cnt,a[i]);
	}
	if(m==1) cout<<cnt;
	else if(m==n) cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
