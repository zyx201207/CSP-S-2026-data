//GZ-J00298 遵义四中 秦近东	 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}sort(a+1,a+1+n);
	cout<<a[n-m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

