//GZ-J00251   遵义市第五十三中学 王前进 
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n+1-m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

