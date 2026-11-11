#include<bits/stdc++.h>
using namespace std;
long long a[200005];
//& yu
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[i];
		return 0;
	}
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
