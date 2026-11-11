#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[200005],b[200005];
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n;i>n-m;i--){
		ans&=a[i];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

