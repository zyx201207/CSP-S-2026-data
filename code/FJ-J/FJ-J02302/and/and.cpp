#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	cout<<a[3];
	
	cout.flush();
	fflush(stdout);
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
