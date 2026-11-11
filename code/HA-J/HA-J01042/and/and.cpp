#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s,ss;
	int a[200010],b[200010],c[200010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n-2;i++){
		sum=max(a[i]&&a[i+1],a[i+1]&&a[i+2]);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
