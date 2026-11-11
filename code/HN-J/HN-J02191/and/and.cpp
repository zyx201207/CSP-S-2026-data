#include<bits/stdc++.h> 
using namespace std;
long long a[200005],ans,n,m;
bool h(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,h);
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

