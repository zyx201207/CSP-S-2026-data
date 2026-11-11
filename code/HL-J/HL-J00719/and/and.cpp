#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	int ans=0;
	for(int i=m;i>=1;i--){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
			ans+=a[i]&a[i+1];
		}
	cout<<ans;
	return 0;
}