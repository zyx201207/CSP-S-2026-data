#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i=n;i++){
		cout<<max(a[i] and a[i+1],a[i+1] and a[i+2]);
	}
	return 0;
}
