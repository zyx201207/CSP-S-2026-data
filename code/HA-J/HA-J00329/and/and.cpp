#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100010],ans=7;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]<=ans&&a[i]==7||a[i]==15||a[i]==31)ans=a[i];
	}
	cout<<ans;
	return 0;
}