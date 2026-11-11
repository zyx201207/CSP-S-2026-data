#include<bits/stdc++.h>

using namespace std;
const int N=5e5+10;
int n,m,ans;
int a[N];
void Main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	ans=a[n];
	for(int i=1;i<=m;i++){
		ans&=a[n-i];
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	Main();
	return 0;
}
