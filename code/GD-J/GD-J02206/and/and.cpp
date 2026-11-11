#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(a[i]&ans);
	}
	cout<<ans;
	return 0;
}
