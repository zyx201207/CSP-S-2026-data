#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool cmp(long long a1,long long b1){
	return a1>b1;
}
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++) ans=ans&a[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
